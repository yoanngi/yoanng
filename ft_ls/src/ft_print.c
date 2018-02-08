/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 16:14:32 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print(t_lst	*recur)
{
	if (recur->path == NULL)
		return ;
	ft_putstr(recur->path);
	ft_putstr(":\n");
	ft_ls_simple(recur->path);
	while (recur)
	{
		if (recur->otherfile != NULL && recur->access == 1)
			ft_print(recur->otherfile);
		recur = recur->next;
	}
}

static void			ft_print_liste(t_lst *recur)
{
	ft_putstr(recur->path);
	ft_putstr(":\n");
	ft_ls_liste(&recur);
	while (recur)
	{
		if (recur->otherfile != NULL && recur->access == 1)
			ft_print_liste(recur->otherfile);
		recur = recur->next;
	}
}

void			ft_print_ls(s_struct *data)
{
	t_lst	*recur;

	recur = data->liste;
	ft_ls_simple(data->file);
	ft_putstr("\n");
	while (recur)
	{
		if (recur->otherfile != NULL && recur->access == 1)
			ft_print(recur->otherfile);
		recur = recur->next;
	}
}

void			ft_print_ls_liste(s_struct *data)
{
	t_lst	*rep;
	t_lst	*cpy;

	if (data->lmin == 0)
	{
		ft_print_ls(data);
		return ;
	}
	rep = data->liste;
	cpy = data->liste;
	ft_ls_liste(&rep);
	while (cpy)
	{
		if (cpy->otherfile != NULL && cpy->access == 1)
			ft_print_liste(cpy->otherfile);
		cpy = cpy->next;
	}

}
