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

void	ft_print_liste(t_lst *recur, s_struct *data)
{
	t_lst *cpy;
	t_lst *ret;

	ft_putchar('\n');
	ft_resize_path(recur->path);
	ft_strdel(&recur->path);
	ft_putstr(":\n");
	cpy = what_sort(data, recur);
	ret = cpy;
	if (ft_print_block_or_not(&ret, data->amin) == 1)
	{
		ft_print_blocks(&ret);
		if (ret->name != NULL)
		{
			ft_ls_liste(&cpy, data->amin);
		}
	}
	while (cpy->next)
	{
		if (cpy->otherfile != NULL && cpy->access == 1)
			ft_print_liste(cpy->otherfile, data);
		if (cpy->otherfile != NULL && cpy->access == 0)
			ft_print_error(cpy->otherfile, data->amin);
		cpy = cpy->next;
	}
}

void	ft_print_ls_liste(s_struct *data)
{
	t_lst *recur;
	t_lst *cpy;

	cpy = data->liste;
	recur = what_sort(data, cpy);
	ft_print_blocks(&cpy);
	ft_ls_liste(&recur, data->amin);
	while (recur->next)
	{
		if (recur->otherfile != NULL && data->rmaj == 1 && recur->access == 1)
			ft_print_liste(recur->otherfile, data);
		if (recur->otherfile != NULL && data->rmaj == 1 && recur->access == 0)
			ft_print_error(recur->otherfile, data->amin);
		recur = recur->next;
	}
}

void	ft_print_error(t_lst *cpy, int amin)
{
	if (amin == 0 && cpy->name[0] == '.')
		return ;
	ft_putstr("\n");
	ft_putstr(cpy->path);
	ft_putstr("\n");
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(cpy->name, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}