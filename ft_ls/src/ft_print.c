/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 13:19:33 by yoginet     ###    #+. /#+    ###.fr     */
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
	char	*error;

	cpy = recur;
	ft_resize_path(recur->path);
	ft_putstr(":\n");
	ft_ls_liste(&recur, secret);
	ft_putstr("\n");
	while (cpy)
	{
		if (cpy->otherfile != NULL && cpy->access == 1)
			ft_print_liste(cpy->otherfile, secret);
		if (cpy->otherfile == NULL && cpy->access == 0)
			error = ft_strdup(cpy->name);
		cpy = cpy->next;
	}
	if (error != NULL)
	{
		ft_error_access(error);
		ft_strdel(&error);
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
	char	*error;

	if (data->lmin == 0)
		ft_print_ls(data, indexfile);
	else
	{
		rep = data->liste;
		cpy = data->liste;
		ft_ls_liste(&rep, data->amin);
		ft_putstr("\n");
		while (cpy)
		{
			if (cpy->otherfile != NULL && cpy->access != 0)
				ft_print_liste(cpy->otherfile, data->amin);
			if (cpy->otherfile == NULL && cpy->access == 0)
				error = ft_strdup(cpy->name);
			cpy = cpy->next;
		}
		if (error != NULL)
		{
			ft_error_access(error);
			ft_strdel(&error);
		}
	}
}
