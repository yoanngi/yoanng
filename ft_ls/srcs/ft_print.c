/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 10:15:39 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_resize_path(char *str)
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

void	ft_print_liste(t_lst *recur, t_struct *data)
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
			ft_ls_liste(&cpy, data->amin);
	}
	while (cpy)
	{
		if (cpy->otherfile != NULL && cpy->access == 1)
			ft_print_liste(cpy->otherfile, data);
		else if (cpy->denied != NULL)
		{
			ft_print_error(cpy->denied, data->amin);
			cpy->denied = NULL;
		}
		cpy = cpy->next;
	}
}

void	ft_print_ls_liste(t_struct *data)
{
	t_lst *recur;
	t_lst *cpy;

	cpy = data->liste;
	ft_print_blocks(&cpy, data->amin);
	recur = what_sort(data, cpy);
	ft_ls_liste(&recur, data->amin);
	while (recur)
	{
		if (recur->otherfile != NULL && data->rmaj == 1 && recur->access == 1)
			ft_print_liste(recur->otherfile, data);
		if (recur->denied != NULL && data->rmaj == 1)
		{
			ft_print_error(recur->denied, data->amin);
			recur->denied = NULL;
		}
		recur = recur->next;
	}
}
