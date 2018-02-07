/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options_r.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 16:44:35 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_insert_path(t_dir *fichierlu, t_lst **data, char *path)
{
	(*data)->path = ft_strjoin(path, "/");
	(*data)->path = ft_strjoin((*data)->path, fichierlu->d_name);
}

static t_lst		*ft_insert_data_hard(t_dir **fichierlu, t_lst **ret)
{
	(*ret)->name = ft_strdup((*fichierlu)->d_name);
	(*ret)->user = ft_get_user(fichierlu);
	(*ret)->groupe = ft_get_groupe(fichierlu);
	(*ret)->date = ft_get_time(fichierlu);
	(*ret)->time = ft_return_time((*ret)->date);
	(*ret)->month = ft_return_month((*ret)->date);
	(*ret)->day = ft_return_day((*ret)->date);
	(*ret)->droit = ft_get_droit(fichierlu);
	(*ret)->size = ft_get_size(fichierlu);
	(*ret)->link = ft_get_link(fichierlu);
	(*ret)->otherfile = NULL;
	return (*ret);
}

static t_lst		*ft_read_repertoire(t_dir **fichierlu, char *path, int nb)
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
	printf("PATH = %s\n", rep->path);
	while ((*fichierlu = readdir(dir)) != NULL)
	{
		printf("Fichier lu = %s |", (*fichierlu)->d_name);
		if (nb == 1)
		//	printf("test\n");
			ft_insert_data_hard(fichierlu, &rep);
		else
			rep->name = ft_strdup((*fichierlu)->d_name);
		printf("ret->droit = %s\n", rep->droit);
		if ((*fichierlu)->d_type == 4 && ft_strcmp((*fichierlu)->d_name, ".") != 0 && ft_strcmp((*fichierlu)->d_name, "..") != 0)
		{
			ft_insert_path(*fichierlu, &rep, path);
			rep->otherfile = ft_read_repertoire(fichierlu, rep->path, nb);
		}
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
		if (data->lmin == 1)
			ft_insert_data_hard(&fichierlu, &lstdata);
		else
			lstdata->name = ft_strdup(fichierlu->d_name);
		printf("DEBUG :fichier lu = %s | ret->droit = %s\n", fichierlu->d_name,lstdata->droit);
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			printf("Un dossier\n");
			ft_insert_path(fichierlu, &lstdata, data->file);
			lstdata->otherfile = ft_read_repertoire(&fichierlu, lstdata->path, data->lmin);
		}
		lstdata->access = 1;
		lstdata->next = ft_lstnew_ls();
		lstdata = lstdata->next;
	}
	closedir(dir);
	return (lstsend);
}
