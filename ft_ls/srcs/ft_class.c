/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_class.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 13:12:05 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 14:21:02 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Reverse list
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

t_lst	*lst_sort_ascii(t_lst *lst)
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
t_lst	*lst_sort_ascii(t_lst *lst)
{
	int		i;
	t_lst	*ret;

	i = 0;
	if (!lst)
		return (NULL);
	ret = lst;
	while (lst->next->name)
	{
		printf("%d AVANT name = %s, next = %s\n", i, lst->name, lst->next->name);
		if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
		{
			lst = lst_swap(lst, lst->next);
			lst = lst_sort_ascii(ret);
		}
		printf("APRES name = %s, next = %s\n\n", lst->name, lst->next->name);
		lst = lst->next;
	}
	return (ret);
}
*/

/*
**	Sort list (time)
**	http://lwh.free.fr/pages/algo/tri/tri.htm
*/

t_lst	*lst_sort_time(t_lst *lst)
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

/*
**	How sort list
*/

t_lst		*what_sort(t_struct *data, t_lst *liste)
{
	if (data->tmin == 1)
		liste = lst_sort_time(liste);
	else
		liste = lst_sort_ascii(liste);
	if (data->rmin == 1)
		liste = ft_reverse_lst(liste);
	return (liste);	
}