/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_class.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 13:12:05 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 16:27:27 by yoginet     ###    #+. /#+    ###.fr     */
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

	start = lst;
	while (lst)
	{
		if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
		{
			ft_swap_lst(&lst, &lst->next);
			lst = start;
		}
		else
			lst = lst->next;
	}
	lst = start;
	return (lst);
}

t_lst			*lst_sort_ascii_inv(t_lst *lst)
{
	t_lst	*start;

	start = lst;
	while (lst)
	{
		if (lst->next && ft_strcmp(lst->name, lst->next->name) < 0)
		{
			ft_swap_lst(&lst, &lst->next);
			lst = start;
		}
		else
			lst = lst->next;
	}
	lst = start;
	return (lst);
}
/*
**	Sort list (time)
*/

t_lst			*lst_sort_time(t_lst *lst)
{
	t_lst	*start;

	start = lst;
	while (lst)
	{
		if (lst->next && lst->date < lst->next->date)
		{
			ft_swap_lst(&lst, &lst->next);
			lst = start;
		}
		else
			lst = lst->next;
	}
	lst = start;
	return (lst);
}

/*
**	How sort list
*/

t_lst			*what_sort(t_struct *data, t_lst *liste)
{
	if (data->tmin == 1)
	{
		liste = lst_sort_ascii_inv(liste);
		liste = lst_sort_time(liste);
	}
	else
		liste = lst_sort_ascii(liste);
	if (data->rmin == 1)
		liste = ft_reverse_lst(liste);
	return (liste);
}

/*********************************************************************/
/*
t_lst			*lst_sort_time(t_lst *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && (lst->date < lst->next->date))
		lst = lst_swap(lst, lst->next);
	else if (lst->next && lst->date == lst->next->date)
		if (lst->next && (lst->date < lst->next->date))
			lst = lst_swap(lst, lst->next);
	lst->next = lst_sort_time(lst->next);
	if (lst->next && (lst->date < lst->next->date))
	{
		lst = lst_swap(lst, lst->next);
		lst->next = lst_sort_time(lst->next);
	}
	else if (lst->next && lst->date == lst->next->date)
	{
		if (lst->next && (lst->date < lst->next->date))
		{
			lst = lst_swap(lst, lst->next);
			lst->next = lst_sort_time(lst->next);
		}
	}
	return (lst);
}
*/

/*
t_lst			*lst_sort_ascii(t_lst *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
		lst = lst_swap(lst, lst->next);
	lst->next = lst_sort_ascii(lst->next);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
	{
		lst = lst_swap(lst, lst->next);
		lst->next = lst_sort_ascii(lst->next);
	}
	return (lst);
}
*/


/*
**	swap list chain
*/
/*
t_lst		*lst_swap(t_lst *lst1, t_lst *lst2)
{
	lst1->next = lst2->next;
	lst2->next = lst1;
	return (lst2);
}
*/