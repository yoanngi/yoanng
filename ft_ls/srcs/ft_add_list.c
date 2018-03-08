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
t_lst			*ft_lstnew_ls(void)
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
	new->link = 0;
	new->access = 1;
	new->otherfile = NULL;
	new->next = NULL;
	if (!new)
		return (NULL);
	return (new);
}

/*
**	Free all data in list
*/
t_lst			*ft_clean_list(t_lst *data)
{
	t_lst	*tmp;
	t_lst	*clean;

	tmp = data;
	while (tmp->name)
	{
		if (tmp->otherfile != NULL)
			ft_clean_list(tmp->otherfile);
		clean = tmp;
		ft_strdel(&tmp->name);
		ft_strdel(&tmp->path);
		ft_strdel(&tmp->user);
		ft_strdel(&tmp->droit);
		ft_strdel(&tmp->groupe);
		ft_strdel(&tmp->day);
		ft_strdel(&tmp->time);
		ft_strdel(&tmp->droit);
		ft_strdel(&tmp->symbol);
		free(tmp->otherfile);
		tmp->otherfile = NULL;
		tmp = tmp->next;
	}
	return (NULL);
}
