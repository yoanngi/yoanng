/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/02 14:56:40 by yoginet     ###    #+. /#+    ###.fr     */
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
	new->access = 1;
	new->otherfile = NULL;
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
**	Free list
*/

t_lst		*ft_clean_list(t_lst *data)
{
	t_lst	*tmp;
	t_lst	*clean;

	tmp = data;
	while (tmp->name)
	{
		if (tmp->otherfile != NULL)
			ft_clean_list(tmp->otherfile);
		clean = tmp;
		ft_strdel(&tmp->path);
		free(tmp->otherfile);
		tmp->otherfile = NULL;
		tmp = tmp->next;
	}
	return (NULL);
}

/*
**	Free datas in list
*/

void		ft_del_infos(t_lst **liste)
{
	ft_strdel(&(*liste)->droit);
	ft_strdel(&(*liste)->user);
	ft_strdel(&(*liste)->groupe);
	ft_strdel(&(*liste)->month);
	ft_strdel(&(*liste)->day);
	ft_strdel(&(*liste)->time);
	ft_strdel(&(*liste)->name);
}
