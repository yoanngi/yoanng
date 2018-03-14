/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options_r.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 14:35:06 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Insert path with '/'
*/

void			ft_insert_path(t_dir *fd, t_lst **data, char *path)
{
	char	*cpy;
	char	*tmp;
	size_t	len;

	len = ft_strlen(path);
	if (len == 1 && path[0] == '/')
		(*data)->path = ft_strjoin(path, fd->d_name);
	else if (path[len - 1] != '/')
	{
		tmp = ft_strdup(path);
		(*data)->path = ft_strjoin(tmp, "/");
		ft_strdel(&tmp);
		cpy = ft_strdup((*data)->path);
		ft_strdel(&(*data)->path);
		(*data)->path = ft_strjoin(cpy, fd->d_name);
		ft_strdel(&cpy);
	}
	else
	{
		cpy = ft_strdup((*data)->path);
		ft_strdel(&(*data)->path);
		(*data)->path = ft_strjoin(cpy, fd->d_name);
		ft_strdel(&cpy);
	}
}

/*
**	Insert datas for class and print
*/

t_lst			*ft_insert_datas(t_dir **fd, t_lst **ret, char *path)
{
	t_stat		buf;

	if (lstat(path, &buf))
	{
		basic_error(path);
		exit(EXIT_FAILURE);
	}
	(*ret)->name = ft_strdup((*fd)->d_name);
	(*ret)->droit = ft_get_droit(buf);
	(*ret)->user = ft_get_user(buf);
	(*ret)->groupe = ft_get_groupe(buf);
	(*ret)->date = ft_get_time(buf);
	ft_minmajorsize(buf, ret);
	(*ret)->link = ft_get_link(buf);
	(*ret)->blocks = ft_get_blocks(buf);
	(*ret)->access = ft_access_or_not(&path);
	if ((*ret)->droit[0] == 'l')
		(*ret)->symbol = ft_get_new_path(&path);
	else
		(*ret)->symbol = NULL;
	(*ret)->otherfile = NULL;
	return (*ret);
}

/*
**	Is directory or not ? check valid or error
*/

static int		ft_check_repertory(t_dir **fl, t_lst **data, t_struct *st)
{
	if (st->amin == 0 && (*fl)->d_name[0] == '.')
	{
		(*data)->otherfile = NULL;
		return (0);
	}
	if ((*data)->access == 1 && ((*fl)->d_type == 4 || (*fl)->d_type == 0) &&
	(ft_strcmp((*fl)->d_name, ".") != 0 &&
	ft_strcmp((*fl)->d_name, "..") != 0))
		(*data)->otherfile = ft_r_repertory(fl, (*data)->path, st);
	else if ((*data)->access == 0 && (*fl)->d_type == 4)
		(*data)->otherfile = ft_return_access_denied(fl, (*data)->path);
	else
		(*data)->otherfile = NULL;
	return (0);
}

/*
**	Recursive -R
*/

t_lst			*ft_r_repertory(t_dir **fd, char *path, t_struct *st)
{
	DIR		*dir;
	t_lst	*rep;
	t_lst	*cpy;

	rep = ft_lstnew_ls();
	cpy = rep;
	dir = opendir(path);
	rep->path = ft_strdup(path);
	while ((*fd = readdir(dir)) != NULL)
	{
		if (rep->name != NULL)
		{
			rep->next = ft_lstnew_ls();
			rep = rep->next;
		}
		ft_insert_path(*fd, &rep, path);
		ft_insert_datas(fd, &rep, rep->path);
		ft_check_repertory(fd, &rep, st);
	}
	closedir(dir);
	return (cpy);
}

/*
**	Read target and take infos
*/

t_lst			*ft_ls_r(t_struct *data, int indexfile)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*lstdata;
	t_lst		*lstsend;

	lstdata = ft_lstnew_ls();
	lstsend = lstdata;
	dir = opendir(data->multifile[indexfile]);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		if (lstdata->name != NULL)
		{
			lstdata->next = ft_lstnew_ls();
			lstdata = lstdata->next;
		}
		if (!(fichierlu->d_name[0] == '.' && data->amin == 0))
		{
			ft_insert_path(fichierlu, &lstdata, data->multifile[indexfile]);
			ft_insert_datas(&fichierlu, &lstdata, lstdata->path);
			if (data->rmaj == 1)
				ft_check_repertory(&fichierlu, &lstdata, data);
		}
	}
	closedir(dir);
	return (lstsend);
}
