/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_suite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 16:03:29 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 11:15:38 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_print_block_or_not(t_lst **data, int secret)
{
	t_lst	*cpy;
	int		i;

	cpy = *data;
	i = 0;
	if (secret == 1)
		return (1);
	while (cpy)
	{
		if (cpy->name == NULL)
			return (0);
		if (ft_strcmp(cpy->name, "..") == 0)
			i++;
		else if (ft_strcmp(cpy->name, ".") == 0)
			i++;
		else
			return (1);
		cpy = cpy->next;
	}
	return (0);
}
