/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 13:48:21 by yoginet     ###    #+. /#+    ###.fr     */
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
