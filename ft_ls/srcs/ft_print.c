/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 13:11:46 by yoginet     ###    #+. /#+    ###.fr     */
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
			return;
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_print_block_or_not(t_lst **data, int secret)
{
	t_lst	*cpy;
	int		i;

	cpy = *data;
	i = 0;
	if (secret == 1)
		return (1);
	while (cpy)
	{
		if (cpy->name == NULL)
			return (0);
		if (ft_strcmp(cpy->name, "..") == 0)
			i++;
		else if (ft_strcmp(cpy->name, ".") == 0)
			i++;
		else
			return (1);
		cpy = cpy->next;
	}
	return (0);
}

void	ft_print_liste(t_lst *recur, int secret)
{
	t_lst *cpy;

	cpy = recur;
	ft_putstr("\n");
	ft_resize_path(recur->path);
	ft_strdel(&recur->path);
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


void	ft_print_ls_liste(s_struct *data)
{
	t_lst *rep;
	t_lst *cpy;

	rep = data->liste;
	cpy = data->liste;
	ft_putstr("total ");
	ft_print_blocks(&rep);
	rep = what_sort(data, cpy);
	ft_ls_liste(&rep, data->amin);
	while (cpy)
	{
		if (cpy->otherfile != NULL && data->rmaj == 1)
		{
			cpy->otherfile = what_sort(data, cpy->otherfile);
			ft_print_liste(cpy->otherfile, data->amin);
		}
		if (cpy->next)
			cpy = cpy->next;
		else
			return ;
	}
	ft_clean_list(data->liste);
}