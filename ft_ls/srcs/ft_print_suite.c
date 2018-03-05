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

static void ft_print(t_lst *recur, int a)
{
	if (recur->path == NULL)
		return;
	ft_putchar('\n');
	ft_resize_path(recur->path);
	ft_putstr(":\n");
	ft_ls_simple(recur->path, a);
	while (recur)
	{
		if (recur->otherfile != NULL && recur->access == 1)
			ft_print(recur->otherfile, a);
		recur = recur->next;
	}
}

void ft_print_ls(s_struct *data, int indexfile)
{
	t_lst *recur;

	recur = what_sort(data, data->liste);
	ft_ls_simple(data->multifile[indexfile], data->amin);
	while (recur)
	{
		if (recur->otherfile != NULL && recur->access == 1)
		{
			recur->otherfile = what_sort(data, recur->otherfile);
			ft_print(recur->otherfile, data->amin);
		}
		recur = recur->next;
	}
}