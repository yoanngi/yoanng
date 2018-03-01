/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_simple.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 13:40:59 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_print_ls_in_order(t_lst **print, int a)
{
	while ((*print)->name)
	{
		if (a == 0 && (*print)->name[0] == '.')
			*print = (*print)->next;
		else
		{
			ft_putstr((*print)->name);
			ft_putstr("\n");
			ft_strdel(&(*print)->name);
			*print = (*print)->next;
		}
	}
}

void				ft_ls_simple(char *target, int a)
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
		data->name = ft_strdup(fichierlu->d_name);
		data->next = ft_lstnew_ls();
		data = data->next;
	}
	closedir(dir);
	ft_class_print(&print, 0, 0);
	ft_print_ls_in_order(&print2, a);
}
