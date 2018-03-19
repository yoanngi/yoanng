/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 13:08:45 by yoginet     ###    #+. /#+    ###.fr     */
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

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
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
**	Create new list for argv
*/

t_rep		*ft_lstnew_argv(void)
{
	t_rep	*new;

	new = (t_rep *)malloc(sizeof(t_rep));
	new->name = NULL;
	new->next = NULL;
	return (new);
}
