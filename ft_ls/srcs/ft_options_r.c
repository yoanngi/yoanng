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

static void			ft_insert_path(t_dir *fichierlu, t_lst **data, char *path)
{
	char	*cpy;
	char	*tmp;
	size_t	len;

	len = ft_strlen(path);
	if (path[len - 1] != '/')
	{
		tmp = ft_strdup(path);
		(*data)->path = ft_strjoin(tmp, "/");
		cpy = ft_strdup((*data)->path);
		ft_strdel(&(*data)->path);
		(*data)->path = ft_strjoin(cpy, fichierlu->d_name);
		ft_strdel(&cpy);
		ft_strdel(&tmp);
	}
	else
	{
		cpy = ft_strdup((*data)->path);
		ft_strdel(&(*data)->path);
		(*data)->path = ft_strjoin(cpy, fichierlu->d_name);
		ft_strdel(&cpy);
	}
}

static t_lst		*ft_insert_data_hard(t_dir **fd, t_lst **ret, char *path)
{
	(*ret)->name = ft_strdup((*fd)->d_name);
	(*ret)->droit = ft_get_droit(&path);
	(*ret)->user = ft_get_user(&path);
	(*ret)->groupe = ft_get_groupe(&path);
	(*ret)->date = ft_get_time(&path);
	(*ret)->time = ft_return_time((*ret)->date);
	(*ret)->month = ft_return_month((*ret)->date);
	(*ret)->day = ft_return_day((*ret)->date);
	(*ret)->size = ft_get_size(&path);
	(*ret)->link = ft_get_link(&path);
	(*ret)->blocks = ft_get_blocks(&path);
	if ((*ret)->droit[0] == 'd' && (*ret)->droit[7] == '-')
	{
		(*ret)->access = ft_access_or_not(&path);
	}
	if ((*ret)->droit[0] == 'l')
		(*ret)->symbol = ft_get_new_path(&path);
	else
		(*ret)->symbol = NULL;
	(*ret)->otherfile = NULL;
	return (*ret);
}

static int			ft_check_repertory(t_dir **fichierlu, t_lst **data, s_struct *structure)
{
	if ((*data)->access == 1 && (*fichierlu)->d_type == 4 && (ft_strcmp((*fichierlu)->d_name, ".") != 0
	&& ft_strcmp((*fichierlu)->d_name, "..") != 0))
		(*data)->otherfile = ft_read_repertoire(fichierlu, (*data)->path, structure);
	else if ((*data)->access == 0 && (*fichierlu)->d_type == 4)
		(*data)->otherfile = ft_return_access_denied(fichierlu, (*data)->path);
	else
		(*data)->otherfile = NULL;
	return (0);
}

t_lst		*ft_read_repertoire(t_dir **fichierlu, char *path, s_struct *structure)
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
		ft_check_repertory(fichierlu, &rep, structure);
//		printf("read_rep (name)-> %s, (path)-> %s, (access) = %d\n\n", rep->name, rep->path, rep->access);
		rep->next = ft_lstnew_ls();
		rep = rep->next;
	}
	closedir(dir);
	return (cpy);
}

t_lst				*ft_ls_r(s_struct *data, int indexfile)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*lstdata;
	t_lst		*lstsend;

	printf("************************************************ START options R\n");
	lstdata = ft_lstnew_ls();
	lstsend = lstdata;
	dir = opendir(data->multifile[indexfile]);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		ft_insert_path(fichierlu, &lstdata, data->multifile[indexfile]);
		ft_insert_data_hard(&fichierlu, &lstdata, lstdata->path);
		if (data->rmaj == 1)
			ft_check_repertory(&fichierlu, &lstdata, data);
//		printf("LS_R (name)-> %s, (path)-> %s, (access) = %d\n", lstdata->name, lstdata->path, lstdata->access);
		lstdata->next = ft_lstnew_ls();
		lstdata = lstdata->next;
	}
	closedir(dir);
	printf("************************************************ END options R\n");
	return (lstsend);
}