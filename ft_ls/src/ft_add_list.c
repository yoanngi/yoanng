/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 11:51:21 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst		*ft_lstnew_ls(void)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->path = NULL;
	new->next = NULL;
	if (!new)
		return (NULL);
	return (new);
}

static void		ft_clean(t_lst	*data)
{
	while (data)
	{
		//ft_strdel(&data->name);
		//ft_strdel(&data->otherfile);
		//ft_strdel(&data->path);
		data = data->next;
	}
}

static void		ft_print(t_lst	*recur)
{
	while (recur)
	{
		if (recur->path != NULL)
		{
			ft_putstr(recur->path);
			ft_putstr(":\n");
			ft_ls_simple(recur->path);
			ft_putstr("\n");
			if (recur->otherfile != NULL)
			{
				while (recur->otherfile->next != NULL)
				{
					ft_putstr(recur->otherfile->path);
					ft_putstr(":\n");
					ft_ls_simple(recur->otherfile->path);
					ft_putstr("\n");
					recur->otherfile = recur->otherfile->next;
				}
			}
		}
		recur = recur->next;
	}
}

void	ft_print_ls(s_struct *data)
{
	t_lst	*recur;
	t_lst	*clean;

	recur = data->liste;
	clean = data->liste;
	ft_ls_simple(data->file);
	ft_putstr("\n");
	ft_print(recur);
	ft_clean(clean);
}
