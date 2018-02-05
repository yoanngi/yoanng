/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options_r.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 16:45:10 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_insert_path(t_dir *fichierlu, t_lst **data, char *path)
{
	(*data)->path = ft_strjoin(path, "/");
	(*data)->path = ft_strjoin((*data)->path, fichierlu->d_name);
}

static t_lst		ft_insert_data_hard(t_dir **fichierlu)
{
	t_lst	*cpy;

	cpy->user = ft_get_user(&fichierlu);
	cpy->groupe = ft_get_groupe(&fichierlu);
	cpy->date = ft_get_time(&fichierlu);
	cpy->droit = ft_get_droit(&fichierlu);
	cpy->size = ft_get_size(&fichierlu);
	cpy->link = ft_get_link(&fichierlu);
	return (cpy);
}

static t_lst		*ft_read_repertoire(t_dir **fichierlu, char *path)
{
	DIR		*dir;
	t_lst	*rep;
	t_lst	*cpy;

	rep = ft_lstnew_ls();
	cpy	= rep;
	if (ft_check_permissions(path, &rep) == 0)
		return (rep);
	dir = opendir(path);
	rep->path = ft_strdup(path);
	while ((*fichierlu = readdir(dir)) != NULL)
	{
		rep->name = ft_strdup((*fichierlu)->d_name);
		if ((*fichierlu)->d_type == 4 && ft_strcmp((*fichierlu)->d_name, ".") != 0 && ft_strcmp((*fichierlu)->d_name, "..") != 0)
		{
			ft_insert_path(*fichierlu, &rep, path);
			rep->otherfile = ft_read_repertoire(fichierlu, rep->path);
		}
		else
			rep->otherfile = NULL;
		rep->access = 1;
		rep->next = ft_lstnew_ls();
		rep = rep->next;
	}
	closedir(dir);
	return (cpy);
}

t_lst				*ft_ls_r(s_struct *data)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*lstdata;
	t_lst		*lstsend;

	lstdata = ft_lstnew_ls();
	lstsend = lstdata;
	dir = opendir(data->file);
	while ((fichierlu = readdir(dir)) != NULL)
	{

		// A modifier, pas fini
		if (data->lmin == 1)
			lstdata = ft_insert_data_hard(&fichierlu, &lstdata);
		else
			lstdata = ft_insert_data_simple(&fichierlu, &)
		lstdata->name = ft_strdup(fichierlu->d_name);
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			ft_insert_path(fichierlu, &lstdata, data->file);
			lstdata->otherfile = ft_read_repertoire(&fichierlu, lstdata->path);
		}
		else
			lstdata->otherfile = NULL;
		lstdata->access = 1;
		lstdata->next = ft_lstnew_ls();
		lstdata = lstdata->next;
	}
	closedir(dir);
	return (lstsend);
}
