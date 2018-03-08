/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_suite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 16:03:29 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 15:14:39 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_ls_simple_sort_two(t_lst *lst)
{
		while (lst->next)
		{
			if (lst->name[0] == '.')
				lst = lst->next;
			else
			{
				ft_putstr(lst->name);
				ft_putstr("\n");
				lst = lst->next;
			}
		}
}

static void	ft_ls_simple_sort(t_lst *lst, int amin)
{
	if (amin == 1)
	{
		while (lst->next)
		{
			ft_putstr(lst->name);
			ft_putstr("\n");
			lst = lst->next;
		}
	}
	else
		ft_ls_simple_sort_two(lst);
}

static void ft_print(t_lst *recur, s_struct *data)
{
	t_lst *cpy;
	t_lst *ret;

	ft_putchar('\n');
	ft_resize_path(recur->path);
	ft_strdel(&recur->path);
	ft_putstr(":\n");
	cpy = what_sort(data, recur);
	ret = cpy;
	ft_ls_simple_sort(cpy, data->amin);
	while (ret)
	{
		if (ret->otherfile != NULL && ret->access == 1)
			ft_print(ret->otherfile, data);
		if (ret->otherfile != NULL && ret->access == 0)
			ft_print_error(ret->otherfile);
		ret = ret->next;
	}
}

void 		ft_print_ls(s_struct *data)
{
	t_lst *recur;
	t_lst *cpy;

	cpy = data->liste;
	recur = what_sort(data, cpy);
	ft_ls_simple_sort(recur, data->amin);
	while (recur->next)
	{
		if (recur->otherfile != NULL && recur->access == 1)
			ft_print(recur->otherfile, data);
		if (cpy->otherfile != NULL && recur->access == 0)
			ft_print_error(recur->otherfile);
		recur = recur->next;
	}
}