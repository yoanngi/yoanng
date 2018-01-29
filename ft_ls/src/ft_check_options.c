/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 15:26:17 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_nb_options(s_struct *data)
{
	int i;

	i = 0;
	if (data->tiret == 1)
		i += 1;
	if (data->rmin == 1)
		i += 1;
	if (data->rmaj == 1)
		i += 1;
	if (data->amin == 1)
		i += 1;
	if (data->tmin == 1)
		i += 1;
	if (data->lmin == 1)
		i += 1;
	return (i);
}

static void		ft_ls_r(s_struct *data)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*lstdata;

	lstdata = ft_lstnew_ls();
	data->liste = lstdata;
	dir = opendir(data->file);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		lstdata->name = ft_strdup(fichierlu->d_name);
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 &&
	ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			lstdata->type = 4;
			lstdata->fd = fichierlu;
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
	data->nb_options = ft_nb_options(data);
	if (data->rmaj == 1)
		ft_ls_r(data);
	ft_print_lst(data);
}