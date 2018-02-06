/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 16:30:19 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst		*ft_lstnew_ls(void)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->name = NULL;
	new->path = NULL;
	new->user = NULL;
	new->groupe = NULL;
	new->date = NULL;
	new->droit = NULL;
	new->size = 0;
	new->link = 0;
	new->otherfile = NULL;
	new->next = NULL;
	if (!new)
		return (NULL);
	return (new);
}

void		ft_swap_lst(t_lst **s1, t_lst **s2)
{
	t_lst *tmp;

	tmp = ft_lstnew_ls();
	tmp->name = (*s1)->name;
	tmp->path = (*s1)->path;
	tmp->access = (*s1)->access;
	tmp->otherfile = (*s1)->otherfile;
	(*s1)->name = (*s2)->name;
	(*s1)->path = (*s2)->path;
	(*s1)->access = (*s2)->access;
	(*s1)->otherfile = (*s2)->otherfile;
	(*s2)->name = tmp->name;
	(*s2)->path = tmp->path;
	(*s2)->access = tmp->access;
	(*s2)->otherfile = tmp->otherfile;
	free(tmp);
}
