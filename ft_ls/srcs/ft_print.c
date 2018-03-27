/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 15:40:36 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_resize_path(char *str)
{
	int i;
	int end;

	i = 0;
	end = ft_strlen(str);
	while (str[i])
	{
		if (i == (end - 2))
			return ;
		ft_putchar(str[i]);
		i++;
	}
	ft_strdel(&str);
}

t_lst		*ft_print_liste(t_lst *recur, t_struct *data)
{
	t_lst *cpy;
	t_lst *ret;

	ft_putchar('\n');
	ft_resize_path(recur->path);
	ft_putstr(":\n");
	cpy = what_sort(data, recur);
	ret = cpy;
	if (ft_print_block_or_not(&ret, data->amin) == 1)
	{
		ft_print_blocks(&ret, data->amin);
		if (ret->name != NULL)
			ft_ls_liste(&cpy, data->amin, data->omin);
	}
	while (cpy)
	{
		if (cpy->otherfile != NULL && cpy->access == 1)
			cpy->otherfile = ft_print_liste(cpy->otherfile, data);
		else if (cpy->denied != NULL)
			cpy->denied = ft_print_error(cpy->denied, data->amin);
		cpy = cpy->next;
	}
	return (ret);
}

void		ft_print_ls_liste(t_struct *data)
{
	t_lst *recur;
	t_lst *cpy;

	cpy = data->liste;
	if (data->lmin == 1 && ft_print_block_or_not(&cpy, data->amin) == 1)
		ft_print_blocks(&cpy, data->amin);
	recur = what_sort(data, cpy);
	data->liste = recur;
	ft_ls_liste(&recur, data->amin, data->omin);
	while (recur)
	{
		if (recur->otherfile != NULL && data->rmaj == 1 && recur->access == 1)
			recur->otherfile = ft_print_liste(recur->otherfile, data);
		if (recur->denied != NULL && data->rmaj == 1)
		{
			ft_print_error(recur->denied, data->amin);
			recur->denied = NULL;
		}
		recur = recur->next;
	}
}
