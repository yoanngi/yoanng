/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 11:29:05 by yoginet     ###    #+. /#+    ###.fr     */
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

static void		ft_ls_r(DIR *dir)
{
	t_dir		*fichierlu;
	t_lst		*data;
	t_lst		*cpy;
	int			i;

	i = 0;
	data = ft_add_list();
	cpy = data;
	if ((dir = opendir(".")) == NULL)
	{
		perror("Error\n");
		exit(1);
	}
	while ((fichierlu = readdir(dir)) != NULL)
	{
		ft_putstr(fichierlu->d_name);
		if (fichierlu->d_type == 4)
		{
			ft_list_add_ls(data, fichierlu);
			ft_putstr("\n");
			i++;
		}
		else
			ft_putstr("\n");
	}
//	ft_print_lst(cpy);
	closedir(dir);
}

void			ft_check_options(s_struct *data, DIR *dir)
{
	int		i;

	i = 0;
	data->nb_options = ft_nb_options(data);
	if (data->rmaj == 1)
		ft_ls_r(dir);
}
