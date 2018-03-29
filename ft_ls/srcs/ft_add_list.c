/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 14:13:38 by yoginet     ###    #+. /#+    ###.fr     */
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
**	Create new list for argv
*/

t_rep		*ft_lstnew_argv(void)
{
	t_rep	*new;

	new = (t_rep *)malloc(sizeof(t_rep));
	new->name = NULL;
	new->date = 0;
	new->next = NULL;
	return (new);
}

/*
**	Swap datas
*/

void		ft_swap_data(t_lst **s1, t_lst *s2)
{
	(*s1)->name = s2->name;
	(*s1)->path = s2->path;
	(*s1)->user = s2->user;
	(*s1)->groupe = s2->groupe;
	(*s1)->droit = s2->droit;
	(*s1)->symbol = s2->symbol;
	(*s1)->access = s2->access;
	(*s1)->size = s2->size;
	(*s1)->minor = s2->minor;
	(*s1)->major = s2->major;
	(*s1)->link = s2->link;
	(*s1)->date = s2->date;
	(*s1)->blocks = s2->blocks;
	(*s1)->otherfile = s2->otherfile;
	(*s1)->denied = s2->denied;
}

void		ft_swap_lst(t_lst **s1, t_lst **s2)
{
	t_lst	cpy;

	cpy = **s1;
	ft_swap_data(s1, *s2);
	ft_swap_data(s2, &cpy);
}
