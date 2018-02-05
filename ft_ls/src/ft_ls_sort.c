/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_sort.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 10:55:18 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 13:14:00 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
/*
static int		ft_sort_date(t_lst **prime, t_lst **second)
{
	
}

t_lst			ft_class_print_t(t_lst **data)
{
	t_lst	*cpy;
	t_lst	*ret;
	int		i;
	int		cmp;

	i = 0;
	cmp = 0;
	cpy = *data;
	ret = *data;
	cpy = cpy->next;
	if (!(*data) || (*data)->name == NULL || (cpy->name == NULL && cpy->next == NULL))
		return (ret);
	while((*data)->name != NULL && cpy->name != NULL)
	{
		if (ft_sort_date(data, &cpy) == 0)
		{
			ft_swap_lst(data, &cpy);
			i = 1;
		}
		cmp++;
		if (cpy->next != NULL || (*data)->next != NULL)
		{
			cpy = cpy->next;
			*data = (*data)->next;
		}
		else if (cmp > 2 && i == 1)
		{
			free(cpy);
			ft_class_print(&ret);
		}
	}
	if (cmp > 2 && i == 1)
		ft_class_print(&ret);
	return(ret);
}*/
