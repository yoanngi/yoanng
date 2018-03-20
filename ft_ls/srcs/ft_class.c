/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_class.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 13:12:05 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 16:36:50 by yoginet     ###    #+. /#+    ###.fr     */
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
**	http://lwh.free.fr/pages/algo/tri/tri.htm
*/

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

/*
**	Sort list (time)
**	http://lwh.free.fr/pages/algo/tri/tri.htm
*/

t_lst			*lst_sort_time(t_lst *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && lst->date < lst->next->date)
		lst = lst_swap(lst, lst->next);
	lst->next = lst_sort_time(lst->next);
	if (lst->next && lst->date < lst->next->date)
	{
		lst = lst_swap(lst, lst->next);
		lst->next = lst_sort_time(lst->next);
	}
	return (lst);
}

/*
t_lst			*lst_sort_time(t_lst *lst)
{
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
