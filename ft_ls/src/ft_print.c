/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 16:29:04 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_resize_path(char *str)
{
	int		i;
	int		end;

	i = 0;
	end = ft_strlen(str);
	while (str[i])
	{
		if (i == (end - 2))
			return ;
		ft_putchar(str[i]);
		i++;
	}
}

static void		ft_print(t_lst *recur)
{
	if (recur->path == NULL)
		return ;
	ft_resize_path(recur->path);
	ft_putstr(":\n");
	ft_ls_simple(recur->path);
	while (recur)
	{
		if (recur->otherfile != NULL && recur->access == 1)
			ft_print(recur->otherfile);
		recur = recur->next;
	}
}

static void		ft_print_liste(t_lst *recur, int secret)
{
	t_lst	*cpy;

	cpy = recur;
	ft_putstr("\n");
	ft_resize_path(recur->path);
	ft_putstr(":\n");
	if (ft_print_block_or_not(&recur, secret) == 1)
	{
		ft_putstr("total ");
		ft_print_blocks(&recur);
		if (recur->name != NULL)
		{
			ft_ls_liste(&recur, secret);
		}
	}
	while (cpy)
	{
		if (cpy->otherfile != NULL)
			ft_print_liste(cpy->otherfile, secret);
		cpy = cpy->next;
	}
}

void			ft_print_ls(s_struct *data, int indexfile)
{
	t_lst	*recur;

	recur = data->liste;
	ft_ls_simple(data->multifile[indexfile]);
	ft_putstr("\n");
	while (recur)
	{
		if (recur->otherfile != NULL && recur->access == 1)
			ft_print(recur->otherfile);
		recur = recur->next;
	}
}

void			ft_print_ls_liste(s_struct *data, int indexfile)
{
	t_lst	*rep;
	t_lst	*cpy;

	if (data->lmin == 0)
		ft_print_ls(data, indexfile);
	else
	{
		rep = data->liste;
		cpy = data->liste;
		ft_putstr("total ");
		ft_print_blocks(&rep);
		ft_ls_liste(&rep, data->amin);
		ft_putstr("\n");
		while (cpy)
		{
			if (cpy->otherfile != NULL)
				ft_print_liste(cpy->otherfile, data->amin);
			cpy = cpy->next;
		}
	}
}
