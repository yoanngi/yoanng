/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 15:40:07 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_read_repertoire(t_lst *docs, t_dir *fichierlu)
{
	DIR		*dir;
	t_lst	*rep;

	rep = ft_lstnew_ls();
	docs->docs = rep;
	dir = opendir(docs->name);
	printf("ft_read_repertoire\n");
	while ((fichierlu = readdir(dir)) != NULL)
	{
		printf("tour de boucle readrepertoire\n");
		rep->name = ft_strdup(fichierlu->d_name);
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			printf("Encore un fichier repertoire -> %s\n", fichierlu->d_name);
			rep->type = 4;
			rep->next = ft_lstnew_ls();
			ft_read_repertoire(rep->next, fichierlu);
		}
		else
			rep->type = 0;
		rep->next = ft_lstnew_ls();
	}
	closedir(dir);
}

static void		ft_ls_r(s_struct *data)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*lstdata;
	t_lst		*lstsend;

	printf("ft_ls_r\n");
	lstdata = ft_lstnew_ls();
	lstsend = lstdata;
	data->liste = lstsend;
	dir = opendir(data->file);

	while ((fichierlu = readdir(dir)) != NULL)
	{
		printf("tour de boucle ft_ls_r -> %s\n", fichierlu->d_name);
		lstdata->name = ft_strdup(fichierlu->d_name);
		lstdata->fd = *dir;
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			lstdata->type = 4;
			lstdata->docs = ft_lstnew_ls();
			lstdata->docs->name = ft_strdup(fichierlu->d_name);
			ft_read_repertoire(lstdata->docs, fichierlu);
		}
		else
			lstdata->type = 0;
		lstdata->next = ft_lstnew_ls();

	}
	closedir(dir);
}

void			ft_check_options(s_struct *data)
{
	int		i;

	i = 0;
	if (data->file == NULL)
		data->file = ft_strdup(".");
	if (data->rmaj == 1)
		ft_ls_r(data);
	ft_print_lst(data);
}
