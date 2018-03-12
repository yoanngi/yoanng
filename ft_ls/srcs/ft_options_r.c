/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options_r.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/02 14:45:45 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_insert_path(t_dir *fichierlu, t_lst **data, char *path)
{
	char	*cpy;
	char	*tmp;
	size_t	len;

	len = ft_strlen(path);
	if (len == 1 && path[0] == '/')
		(*data)->path = ft_strjoin(path, fichierlu->d_name);
	else if (path[len - 1] != '/')
	{
		tmp = ft_strdup(path);
		(*data)->path = ft_strjoin(tmp, "/");
		ft_strdel(&tmp);
		cpy = ft_strdup((*data)->path);
		ft_strdel(&(*data)->path);
		(*data)->path = ft_strjoin(cpy, fichierlu->d_name);
		ft_strdel(&cpy);
	}
	else
	{
		cpy = ft_strdup((*data)->path);
		ft_strdel(&(*data)->path);
		(*data)->path = ft_strjoin(cpy, fichierlu->d_name);
		ft_strdel(&cpy);
	}
}

t_lst			*ft_insert_data_hard(t_dir **fd, t_lst **ret, char *path)
{
	(*ret)->name = ft_strdup((*fd)->d_name);
	(*ret)->droit = ft_get_droit(&path);
	(*ret)->user = ft_get_user(&path);
	(*ret)->groupe = ft_get_groupe(&path);
	(*ret)->date = ft_get_time(&path);
	(*ret)->time = ft_return_time((*ret)->date);
	(*ret)->month = ft_return_month((*ret)->date);
	(*ret)->day = ft_return_day((*ret)->date);
	if ((*ret)->droit[0] == 'c' || (*ret)->droit[0] == 'b')
	{
		(*ret)->minor = ft_get_minor(&path);
		(*ret)->major = ft_get_major(&path);
	}
	else
		(*ret)->size = ft_get_size(&path);
	(*ret)->link = ft_get_link(&path);
	(*ret)->blocks = ft_get_blocks(&path);
	(*ret)->access = ft_access_or_not(&path);
	if ((*ret)->droit[0] == 'l')
		(*ret)->symbol = ft_get_new_path(&path);
	else
		(*ret)->symbol = NULL;
	(*ret)->otherfile = NULL;
	return (*ret);
}

static int		ft_check_repertory(t_dir **fl, t_lst **data, s_struct *st)
{
	if (st->amin == 0 && (*fl)->d_name[0] == '.')
	{
		(*data)->otherfile = NULL;
		return (0);
	}
	if ((*data)->access == 1 && ((*fl)->d_type == 4 || (*fl)->d_type == 0) &&
	(ft_strcmp((*fl)->d_name, ".") != 0 &&
	ft_strcmp((*fl)->d_name, "..") != 0))
		(*data)->otherfile = ft_read_repertoire(fl, (*data)->path, st);
	else if ((*data)->access == 0 && (*fl)->d_type == 4)
		(*data)->otherfile = ft_return_access_denied(fl, (*data)->path);
	else
		(*data)->otherfile = NULL;
	return (0);
}

t_lst			*ft_read_repertoire(t_dir **fichierlu, char *path, s_struct *st)
{
	DIR		*dir;
	t_lst	*rep;
	t_lst	*cpy;

	rep = ft_lstnew_ls();
	cpy = rep;
	dir = opendir(path);
	rep->path = ft_strdup(path);
	while ((*fichierlu = readdir(dir)) != NULL)
	{
		ft_insert_path(*fichierlu, &rep, path);
		ft_insert_data_hard(fichierlu, &rep, rep->path);
		ft_check_repertory(fichierlu, &rep, st);
		rep->next = ft_lstnew_ls();
		rep = rep->next;
	}
	closedir(dir);
	return (cpy);
}

t_lst			*ft_ls_r(s_struct *data, int indexfile)
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
		ft_insert_path(fichierlu, &lstdata, data->multifile[indexfile]);
		ft_insert_data_hard(&fichierlu, &lstdata, lstdata->path);
		if (data->rmaj == 1)
			ft_check_repertory(&fichierlu, &lstdata, data);
		lstdata->next = ft_lstnew_ls();
		lstdata = lstdata->next;
	}
	closedir(dir);
	return (lstsend);
}
