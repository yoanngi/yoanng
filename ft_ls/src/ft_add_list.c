/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 11:35:25 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

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
	new->size = 0;
	new->link = 0;
	new->otherfile = NULL;
	new->next = NULL;
	if (!new)
		return (NULL);
	return (new);
}

void			ft_swap_lst(t_lst **s1, t_lst **s2)
{
	t_lst *tmp;

	tmp = ft_lstnew_ls();
	tmp->name = (*s1)->name;
	tmp->path = (*s1)->path;
	tmp->user = (*s1)->user;
	tmp->groupe = (*s1)->groupe;
	tmp->date = (*s1)->date;
	tmp->droit = (*s1)->droit;
	tmp->size = (*s1)->size;
	tmp->link = (*s1)->link;
	tmp->symbol = (*s1)->symbol;
	tmp->otherfile = (*s1)->otherfile;
	(*s1)->name = (*s2)->name;
	(*s1)->path = (*s2)->path;
	(*s1)->user = (*s2)->user;
	(*s1)->groupe = (*s2)->groupe;
	(*s1)->date = (*s2)->date;
	(*s1)->droit = (*s2)->droit;
	(*s1)->size = (*s2)->size;
	(*s1)->link = (*s2)->link;
	(*s1)->symbol = (*s2)->symbol;
	(*s1)->otherfile = (*s2)->otherfile;
	ft_swap_lst2(s2, &tmp);
	free(tmp);
}

void			ft_swap_lst2(t_lst **s2, t_lst **tmp)
{
	(*s2)->name = (*tmp)->name;
	(*s2)->path = (*tmp)->path;
	(*s2)->user = (*tmp)->user;
	(*s2)->groupe = (*tmp)->groupe;
	(*s2)->date = (*tmp)->date;
	(*s2)->droit = (*tmp)->droit;
	(*s2)->size = (*tmp)->size;
	(*s2)->symbol = (*tmp)->symbol;
	(*s2)->link = (*tmp)->link;
	(*s2)->otherfile = (*tmp)->otherfile;
}

void			ft_clean_list(t_lst **data)
{
	t_lst	*tmp;
	t_lst	*tmp_next;

	tmp = *data;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp->name);
		free(tmp->user);
		free(tmp->droit);
		free(tmp->groupe);
		free(&tmp->month);
		free(&tmp->day);
		free(&tmp->time);
		free(tmp);
		tmp = tmp_next;
	}
}
