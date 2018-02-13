/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_simple.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 13:46:44 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_print_ls_in_order(t_lst **print)
{
	t_lst *clear;

	clear = *print;
	while (*print)
	{
		ft_putstr((*print)->name);
		ft_putstr("\n");
		ft_strdel(&(*print)->name);
		*print = (*print)->next;
	}
}

t_lst				*ft_class_print(t_lst **data, int i, int cmp)
{
	t_lst	*cpy;
	t_lst	*ret;

	cpy = *data;
	ret = *data;
	cpy = cpy->next;
	if (!(*data) || (*data)->name == NULL || (cpy->name == NULL &&
	cpy->next == NULL))
		return (ret);
	while ((*data)->name != NULL && cpy->name != NULL)
	{
		if (ft_strcmp((*data)->name, cpy->name) > 0)
		{
			ft_swap_lst(data, &cpy);
			i = 1;
		}
		*data = (*data)->next;
		cpy = cpy->next;
		cmp++;
	}
	if (cmp > 2 && i == 1)
		ft_class_print(&ret, 0, 0);
	return (ret);
}

void				ft_ls_simple(char *target)
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
		basic_error(target);
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
	ft_class_print(&print, 0, 0);
	ft_print_ls_in_order(&print2);
}
