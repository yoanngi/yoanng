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

	ret = recur;
	cpy = what_sort(data, recur);
	ft_putstr("\n");
	ft_resize_path(ret->path);
	ft_strdel(&ret->path);
	ft_putstr(":\n");
	if (recur->access_denied != NULL)
		basic_error(recur->access_denied);
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
		if (cpy->otherfile != NULL && cpy->access_denied == NULL)
			ft_print_liste(cpy->otherfile, data);
		if (cpy->otherfile != NULL && cpy->access_denied != NULL)
			perror(cpy->access_denied);
		cpy = cpy->next;
	}
}

void	ft_print_ls_liste(s_struct *data)
{
	t_lst *rep;
	t_lst *cpy;

	rep = data->liste;
	cpy = what_sort(data, rep);
	rep = cpy;
	ft_print_blocks(&rep);
	ft_ls_liste(&rep, data->amin);
	while (cpy->next)
	{
		if (cpy->otherfile != NULL && data->rmaj == 1 && cpy->access_denied == NULL)
			ft_print_liste(cpy->otherfile, data);
		if (cpy->otherfile != NULL && cpy->access_denied != NULL)
		{
			printf("Sa Marche ! %s\n", cpy->name);
			perror(cpy->access_denied);
		}
		cpy = cpy->next;
	}
}