/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_class.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 13:12:05 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 14:31:56 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Reverse list
**	http://lwh.free.fr/pages/algo/tri/tri.htm
*/

t_lst			*ft_reverse_lst(t_lst *prime)
{
	t_lst	*tete;
	t_lst	*sui;

	tete = NULL;
	sui = NULL;
	while (prime)
	{
		sui = prime->next;
		prime->next = tete;
		tete = prime;
		prime = sui;
	}
	return (tete);
}

/*
**	Sort list (ascii)
*/

t_lst			*lst_sort_ascii(t_lst *lst)
{
	t_lst	*start;
	int		i;

	i = 0;
	start = lst;
	while (lst)
	{
		if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
		{
			ft_swap_lst(&lst, &lst->next);
			i++;
		}
		else
			lst = lst->next;
	}
	if (i > 0)
		lst = lst_sort_ascii(start);
	lst = start;
	return (lst);
}

/*
**	Sort list (time)
*/

static int		lst_sort_suite(t_lst **lst)
{
	int i;

	i = 0;
	if ((*lst)->next && (*lst)->date < (*lst)->next->date)
	{
		ft_swap_lst(lst, &(*lst)->next);
		i++;
	}
	else if ((*lst)->next && (*lst)->date == (*lst)->next->date)
	{
		if ((*lst)->next && ft_strcmp((*lst)->name, (*lst)->next->name) > 0)
		{
			ft_swap_lst(lst, &(*lst)->next);
			i++;
		}
	}
	return (i);
}

t_lst			*lst_sort_time(t_lst *lst)
{
	t_lst	*start;
	int		i;

	i = 0;
	start = lst;
	while (lst)
	{
		i += lst_sort_suite(&lst);
		lst = lst->next;
	}
	if (i > 0)
		lst = lst_sort_time(start);
	lst = start;
	return (lst);
}

/*
**	How sort list
*/

t_lst			*what_sort(t_struct *data, t_lst *liste)
{
	if (data->tmin == 1)
		liste = lst_sort_time(liste);
	else
		liste = lst_sort_ascii(liste);
	if (data->rmin == 1)
		liste = ft_reverse_lst(liste);
	return (liste);
}
