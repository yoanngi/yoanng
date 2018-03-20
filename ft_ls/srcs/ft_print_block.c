/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_block.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 13:20:20 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 11:35:21 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Print total <blocks>
*/

void			ft_print_blocks(t_lst **liste, int amin)
{
	t_lst		*cpy;
	blkcnt_t	total;
	int			compt;

	cpy = *liste;
	total = 0;
	compt = 0;
	while (cpy)
	{
		total += cpy->blocks;
		compt++;
		cpy = cpy->next;
	}
	if (compt > 2 || amin == 1)
	{
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putstr("\n");
	}
}

/*
**	if list = . or .. , no print total
*/

int				ft_print_block_or_not(t_lst **data, int secret)
{
	t_lst	*cpy;
	int		i;

	cpy = *data;
	i = 0;
	if (secret == 1)
		return (1);
	while (cpy)
	{
		if (!(cpy->name[0] == '.'))
			i++;
		cpy = cpy->next;
	}
	if (i > 0)
		return (1);
	return (0);
}
