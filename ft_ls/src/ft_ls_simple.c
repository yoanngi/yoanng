/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_simple.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 15:09:03 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_ls_in_order(t_lst **print)
{
	t_lst *clear;

	clear = *print;
	while (*print)
	{
		ft_putstr((*print)->name);
		ft_putstr("\n");
		*print = (*print)->next;
	}
	//ft_clean(&clear);
}

static t_lst		*ft_class_print(t_lst **data)
{
	t_lst	*cpy;
	t_lst	*ret;
	int		i;

	i = 0;
	cpy = *data;
	ret = *data;
	if ((*data)->next == NULL)
		return (ret);
	while(cpy->next != NULL)
	{
		if (ft_strcmp((*data)->name, cpy->name) > 0)
		{
			ft_swap_lst(data, &cpy);
			i = 1;
		}
		cpy = cpy->next;
		*data = (*data)->next;
	}
	if (i == 1)
		ft_class_print(&ret);
	return(ret);
}

void	ft_ls_simple(char *target)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*data;
	t_lst		*print;
	t_lst		*print2;

	data = ft_lstnew_ls();
	print = data;
	print2 = data;
	if ((dir = opendir(target)) == NULL)
	{
		perror("Impossible d'ouvrir le fichier\n");
		exit(1);
	}
	while ((fichierlu = readdir(dir)) != NULL)
	{
		if ((ft_strcmp(fichierlu->d_name, "..") != 0) &&
	(fichierlu->d_name[0] != '.'))
		{
			data->name = ft_strdup(fichierlu->d_name);
			data->next = ft_lstnew_ls();
			data = data->next;
		}
	}
	closedir(dir);
	ft_class_print(&print);
	ft_print_ls_in_order(&print2);
}
