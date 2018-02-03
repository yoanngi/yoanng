/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options_r.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 15:23:18 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int			ft_check_permissions(char *path)
{
	if (access(path, R_OK) & EACCES)
		return (0);
	else
		return (1);
}

static void			ft_insert_data(t_dir *fichierlu, t_lst **data, char *path)
{
	(*data)->path = ft_strjoin(path, "/");
	(*data)->path = ft_strjoin((*data)->path, fichierlu->d_name);
}

static t_lst		*ft_read_repertoire(t_dir **fichierlu, char *path)
{
	DIR		*dir;
	t_lst	*rep;
	t_lst	*cpy;

	rep = ft_lstnew_ls();
	cpy	= rep;
	if (ft_check_permissions(path) == 0)
	{
		rep->access = 0;
		printf("ACCES DENIED\n");
		return (rep);
	}
	dir = opendir(path);
	rep->path = ft_strdup(path);
	while ((*fichierlu = readdir(dir)) != NULL)
	{
		rep->name = ft_strdup((*fichierlu)->d_name);
		if ((*fichierlu)->d_type == 4 && ft_strcmp((*fichierlu)->d_name, ".") != 0 && ft_strcmp((*fichierlu)->d_name, "..") != 0)
		{
			ft_insert_data(*fichierlu, &rep, path);
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
		lstdata->name = ft_strdup(fichierlu->d_name);
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			ft_insert_data(fichierlu, &lstdata, data->file);
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
