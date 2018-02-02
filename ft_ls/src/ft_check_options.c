/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 15:23:18 by yoginet     ###    #+. /#+    ###.fr     */
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
	int		i;
	t_lst	*rep;
	t_lst	*cpy;

	i = 0;
	dir = opendir(data->path);
	printf("%s:\n", data->path);
	rep = ft_lstnew_ls();
	cpy	= rep;
	while ((fichierlu = readdir(dir)) != NULL)
	{
		printf("%s\n", fichierlu->d_name);
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0 && EACCES == 0)
		{
			i = 1;
			rep->name = ft_strdup(fichierlu->d_name);
			ft_path(rep, data->path, fichierlu->d_name);
			rep->otherfile = ft_read_repertoire(rep, fichierlu);
			rep->next = ft_lstnew_ls();
		}
	}
	closedir(dir);
	if (i == 0)
		return (NULL);
	return (cpy);
}

static t_lst		*ft_ls_r(s_struct *data)
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
		printf("Fichier lu = %s\n", fichierlu->d_name);
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			lstdata->name = ft_strdup(fichierlu->d_name);
			ft_path(lstdata, data->file, fichierlu->d_name);
			lstdata->otherfile = ft_read_repertoire(lstdata, fichierlu);
			lstdata->next = ft_lstnew_ls();
			lstdata = lstdata->next;
		}
	}
	closedir(dir);
	return (lstsend);
}

void				ft_check_options(s_struct *data)
{
	s_struct	*tmp;

	if (data->file == NULL)
		data->file = ft_strdup(".");
	tmp = data;
	if (data->rmaj == 1)// -R
		data->liste = ft_ls_r(data);
/*	if (data->rmin == 1)// -r
		ft_option_r(data);
	if (data->tmin == 1)// -t
		ft_sort(data);
	if (data->amin == 1)// -a
		ft_filecacher(data);
	// Plus qu'a gerer le mode d'affichage */
	ft_putstr("*****************Fonction d'affichage*****************\n");
	//ft_print_ls(data);
}
