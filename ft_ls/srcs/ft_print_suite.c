/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_suite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 16:03:29 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 11:24:23 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_ls_simple_sort_two(t_lst *lst)
{
	while (lst)
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

void			ft_ls_simple_sort(t_lst *lst, int amin)
{
	if (amin == 1)
	{
		while (lst)
		{
			ft_putstr(lst->name);
			ft_putstr("\n");
			lst = lst->next;
		}
	}
	else
		ft_ls_simple_sort_two(lst);
}

static t_lst	*ft_print(t_lst *recur, t_struct *data)
{
	t_lst *cpy;
	t_lst *ret;

	ft_putchar('\n');
	ft_resize_path(recur->path);
	ft_putstr(":\n");
	cpy = what_sort(data, recur);
	ret = cpy;
	ft_ls_simple_sort(cpy, data->amin);
	while (ret)
	{
		if (ret->otherfile != NULL && ret->access == 1)
			ret->otherfile = ft_print(ret->otherfile, data);
		if (ret->denied != NULL)
			ret->denied = ft_print_error(ret->denied, data->amin);
		ret = ret->next;
	}
	return (cpy);
}

void			ft_print_ls(t_struct *data)
{
	t_lst *recur;
	t_lst *cpy;

	cpy = data->liste;
	recur = what_sort(data, cpy);
	data->liste = recur;
	ft_ls_simple_sort(recur, data->amin);
	while (recur)
	{
		if (recur->otherfile != NULL && data->rmaj == 1 && recur->access == 1)
			recur->otherfile = ft_print(recur->otherfile, data);
		if (recur->denied != NULL && data->rmaj == 1)
		{
			ft_print_error(recur->denied, data->amin);
			recur->denied = NULL;
		}
		recur = recur->next;
	}
}
