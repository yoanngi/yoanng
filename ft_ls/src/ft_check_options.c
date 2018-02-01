/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 15:54:30 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static t_lst	*ft_path(t_lst *rep, char *file, char *dossier)
{
	rep->path = ft_strjoin(file, "/");
	rep->path = ft_strjoin(rep->path, dossier);
	return *(&rep);
}

static t_lst		*ft_read_repertoire(t_lst *data, t_dir *fichierlu)
{
	DIR		*dir;
	t_lst	*rep;
	t_lst	*cpy;

	dir = opendir(data->path);
	printf("DEBUG**********data->path = %s\n", data->path);
	rep = ft_lstnew_ls();
	cpy	= rep;
	data->next = cpy;
	while ((fichierlu = readdir(dir)) != NULL)
	{
		printf("read_repertoire-> fichierlu = %s\n", fichierlu->d_name);
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			rep->name = ft_strdup(fichierlu->d_name);
			ft_path(rep, data->path, fichierlu->d_name);
			rep->otherfile = ft_read_repertoire(rep->next, fichierlu);
		}
	}
	closedir(dir);
	return (cpy);
}

static void		ft_ls_r(s_struct *data)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*lstdata;
	t_lst		*lstsend;

	lstdata = ft_lstnew_ls();
	lstsend = lstdata;
	data->liste = lstsend;
	dir = opendir(data->file);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			lstdata->name = ft_strdup(fichierlu->d_name);
			ft_path(lstdata, data->file, fichierlu->d_name);
			lstdata->otherfile = ft_read_repertoire(lstdata, fichierlu);
			lstdata->next = ft_lstnew_ls();
		}
	}
	closedir(dir);
}

void			ft_check_options(s_struct *data)
{
	s_struct	*tmp;

	if (data->file == NULL)
		data->file = ft_strdup(".");
	tmp = data;
	if (data->rmaj == 1)
		ft_ls_r(data);
	ft_putstr("*****************Fonction d'affichage*****************\n");
	ft_print_ls(data);
}
