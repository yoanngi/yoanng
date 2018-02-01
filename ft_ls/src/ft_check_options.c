/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 16:40:21 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static t_lst	*ft_path(t_lst *rep, char *file, char *dossier)
{
	rep->name = ft_strjoin(file, "/");
	rep->name = ft_strjoin(rep->name, dossier);
	return *(&rep);
}

static t_lst		*ft_read_repertoire(t_lst *docs, t_dir *fichierlu)
{
	DIR		*dir;
	t_lst	*rep;

	rep = ft_lstnew_ls();
	docs->docs = rep;
	dir = opendir(docs->name);
	printf("*****************************************ft_read_repertoire\n");
	printf("DEBUG -> fichierlu %s\n", fichierlu->d_name);
	printf("DEBUG -> dir %s\n", docs->name);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		printf("tour de boucle read_repertoire-> fichierlu = %s\n", fichierlu->d_name);
		rep->name = ft_strdup(fichierlu->d_name);
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			printf("Encore un fichier repertoire -> %s\n", fichierlu->d_name);
			rep->type = 4;
			rep->next = ft_lstnew_ls();
			ft_path(rep, docs->name, fichierlu->d_name);
			printf("repertoire path--------->%s\n", rep->name);
			ft_read_repertoire(rep, fichierlu);
		}
		else
			rep->type = 0;
		rep->next = ft_lstnew_ls();
	}
	closedir(dir);
	return (rep);
}

static void		ft_ls_r(s_struct *data)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*lstdata;
	t_lst		*lstsend;

	lstdata = ft_lstnew_ls();
	lstsend = lstdata;
	data->liste = lstdata;
	data->listeclean = lstsend;
	dir = opendir(data->file);

	while ((fichierlu = readdir(dir)) != NULL)
	{
		printf("tour de boucle ft_ls_r -> %s\n", fichierlu->d_name);
		lstdata->name = ft_strdup(fichierlu->d_name);
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			printf("C'est un repertoire--------->%s\n", lstdata->name);
			lstdata->type = 4;
			lstdata->docs = ft_lstnew_ls();
			ft_path(lstdata, data->file, fichierlu->d_name);
			printf("repertoire path--------->%s\n", lstdata->name);
			lstdata->docs = ft_read_repertoire(lstdata, fichierlu);
		}
		else
			lstdata->type = 0;
		lstdata->next = ft_lstnew_ls();

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
	ft_print_lst(data);
}
