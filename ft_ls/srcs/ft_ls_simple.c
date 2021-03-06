/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_simple.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 12:59:54 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_clean_simple(t_lst **src)
{
	t_lst	*clear;
	t_lst	*cpy;

	clear = *src;
	while (clear)
	{
		cpy = clear;
		clear = clear->next;
		free(cpy);
	}
	free(clear);
}

static void			ft_print_ls_in_order(t_lst **print, int a)
{
	t_lst	*cpy;

	cpy = *print;
	while (cpy)
	{
		if (a == 0 && cpy->name[0] == '.')
		{
			ft_strdel(&cpy->name);
			cpy = cpy->next;
		}
		else
		{
			ft_putstr(cpy->name);
			ft_putstr("\n");
			ft_strdel(&cpy->name);
			cpy = cpy->next;
		}
	}
	ft_clean_simple(print);
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
		if (data->name != NULL)
		{
			data->next = ft_lstnew_ls();
			data = data->next;
		}
		data->name = ft_strdup(fichierlu->d_name);
	}
	closedir(dir);
	print2 = lst_sort_ascii(print);
	ft_print_ls_in_order(&print2, a);
}
