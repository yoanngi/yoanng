/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_class.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 13:12:05 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/02 12:50:42 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst				*ft_class_print(t_lst **data, int i, int cmp)
{
	t_lst	*s1;
	t_lst	*s2;

	s1 = *data;
	s2 = (*data)->next;
	if (!(*data) || s1->name == NULL || (s2->name == NULL &&
				s2->next == NULL))
		return (*data);
	while (s1->name != NULL || s2->name != NULL)
	{
		if (ft_strcmp(s1->name, s2->name) > 0)
		{
			ft_swap_lst(&s1, &s2);
			i = 1;
		}
		s1 = s1->next;
		s2 = s2->next;
		cmp++;
	}
	if (cmp > 2 && i == 1)
		ft_class_print(data, 0, 0);
	return (*data);
}
