/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 15:54:32 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst		*ft_lstnew_ls(void)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->next = NULL;
	if (!new)
		return (NULL);
	return (new);
}

static void		ft_clean(t_lst	*data)
{
	while (data)
	{
		ft_strdel(&data->name);
		ft_strdel(&data->path);
		data = data->next;
	}
}

void	ft_print_ls(s_struct *data)
{
	t_lst	*recur;
	t_lst	*clean;

	recur = data->liste;
	clean = recur;
	ft_ls_simple(data->file);
	ft_putstr("\n");
	while (recur)
	{
		ft_putstr(data->liste->path);
		ft_putstr(":\n");
		ft_ls_simple(data->liste->path);
		ft_putstr("\n");
		recur = recur->next;
	}
	ft_clean(clean);
}
