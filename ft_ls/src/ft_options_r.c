/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options_r.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 16:40:15 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_insert_path(t_dir *fichierlu, t_lst **data, char *path)
{
	char	*cpy;

	(*data)->path = ft_strjoin(path, "/");
	cpy = ft_strdup((*data)->path);
	ft_strdel(&(*data)->path);
	(*data)->path = ft_strjoin(cpy, fichierlu->d_name);
	ft_strdel(&cpy);
}

static t_lst		*ft_insert_data_hard(t_dir **fd, t_lst **ret, char *path)
{
	if (ft_check_permissions(path, ret) == 1)
	{
		(*ret)->name = ft_strdup((*fd)->d_name);
		(*ret)->user = ft_get_user(&path);
		(*ret)->groupe = ft_get_groupe(&path);
		(*ret)->date = ft_get_time(&path);
		(*ret)->time = ft_return_time((*ret)->date);
		(*ret)->month = ft_return_month((*ret)->date);
		(*ret)->day = ft_return_day((*ret)->date);
		(*ret)->droit = ft_get_droit(&path);
		(*ret)->size = ft_get_size(&path);
		(*ret)->link = ft_get_link(&path);
		(*ret)->otherfile = NULL;
		return (*ret);
	}
	return (*ret);
}

static t_lst		*ft_read_repertoire(t_dir **fichierlu, char *path, int nb)
{
	DIR		*dir;
	t_lst	*rep;
	t_lst	*cpy;

	rep = ft_lstnew_ls();
	cpy = rep;
	if (ft_check_permissions(path, &rep) == 0)
		return (rep);
	dir = opendir(path);
	rep->path = ft_strdup(path);
	while ((*fichierlu = readdir(dir)) != NULL)
	{
		ft_insert_path(*fichierlu, &rep, path);
		if (nb == 1)
			ft_insert_data_hard(fichierlu, &rep, rep->path);
		else
			rep->name = ft_strdup((*fichierlu)->d_name);
		if ((*fichierlu)->d_type == 4 && ft_strcmp((*fichierlu)->d_name, ".")
				!= 0 && ft_strcmp((*fichierlu)->d_name, "..") != 0 && ft_check_permissions(path, &rep) == 1)
			rep->otherfile = ft_read_repertoire(fichierlu, rep->path, nb);
		//		rep->access = 1;
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

	lstdata = ft_lstnew_ls();
	lstsend = lstdata;
	if (ft_check_permissions(data->multifile[indexfile], &lstdata) == 0)
		return (lstsend);
	dir = opendir(data->multifile[indexfile]);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		ft_insert_path(fichierlu, &lstdata, data->multifile[indexfile]);
		if (data->lmin == 1)
			ft_insert_data_hard(&fichierlu, &lstdata, lstdata->path);
		else
			lstdata->name = ft_strdup(fichierlu->d_name);
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0
				&& ft_strcmp(fichierlu->d_name, "..") != 0)
			lstdata->otherfile = ft_read_repertoire(&fichierlu, lstdata->path,
					data->lmin);
		lstdata->access = 1;
		lstdata->next = ft_lstnew_ls();
		lstdata = lstdata->next;
	}
	closedir(dir);
	return (lstsend);
}
