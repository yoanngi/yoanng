/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 14:12:04 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Create new list
*/

t_lst		*ft_lstnew_ls(void)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->name = NULL;
	new->symbol = NULL;
	new->path = NULL;
	new->user = NULL;
	new->groupe = NULL;
	new->droit = NULL;
	new->date = 0;
	new->size = 0;
	new->minor = 0;
	new->major = 0;
	new->link = 0;
	new->blocks = 0;
	new->access = 1;
	new->otherfile = NULL;
	new->denied = NULL;
	new->next = NULL;
	if (!new)
		return (NULL);
	return (new);
}

/*
**	swap list chain
*/

t_lst		*lst_swap(t_lst *lst1, t_lst *lst2)
{
	lst1->next = lst2->next;
	lst2->next = lst1;
	return (lst2);
}

/*
**	Free list and datas
*/

t_lst		*ft_clean_list(t_lst **data)
{
	t_lst	*clear;
	t_lst	*cpy;

	clear = *data;
	while (clear)
	{
		if (clear->otherfile != NULL)
			ft_clean_list(&clear->otherfile);
		else if (clear->denied != NULL)
		{
			ft_strdel(&clear->denied->path);
			ft_strdel(&clear->denied->name);
			free(clear->denied);
		}
//		ft_strdel(&clear->path);
		ft_strdel(&clear->droit);
		ft_strdel(&clear->user);
		ft_strdel(&clear->groupe);
		ft_strdel(&clear->name);
		ft_strdel(&clear->symbol);
		cpy = clear;
		clear = clear->next;
		free(cpy);
		cpy = NULL;
	}
	free(clear);
	clear = NULL;
	return (NULL);
}

/*
**	Free tab in struct and free struct
*/

void		ft_del_struct(t_struct *data)
{
	int i;

	i = 0;
	while (i++ != data->argc)
		free(data->multifile[i]);
	free(data->liste);
	free(data);
}
