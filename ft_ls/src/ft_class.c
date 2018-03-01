/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_class.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 13:12:05 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 16:13:40 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst				*ft_class_print(t_lst **data, int i, int cmp)
{
	t_lst	*s0;
	t_lst	*s1;
	t_lst	*s2;

	s0 = *data;
	s1 = (*data)->next;
	s2 = (*data)->next->next;
	if (!(*data) || s1->name == NULL || (s2->name == NULL &&
				s2->next == NULL))
		return (*data);
	while (s1->name != NULL || s2->name != NULL)
	{
		if (ft_strcmp(s1->name, s2->name) > 0)
		{
			printf("Avant = s0 : %s, s1 : %s, s2 : %s\n", s0->name, s1->name, s2->name);
			ft_swap_lst(&s0, &s1, &s2);
			printf("Apres = s0 : %s, s1 : %s, s2 : %s\n\n", s0->name, s1->name, s2->name);
			i = 1;
		}
		s0 = s0->next;
		s1 = s1->next;
		s2 = s2->next;
		cmp++;
	}
	printf("end boucle\n");
	if (cmp > 2 && i == 1)
		ft_class_print(data, 0, 0);
	printf("EENNNNNNNNNNNNNNDDDDDDDDDDDDDDDDDDD\n\n");
	return (*data);
}
