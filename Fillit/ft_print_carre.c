/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo_tetra.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 15:50:47 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 11:21:40 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_carre(char **tab, int len)
{
	int x;
	int y;

	x = 0;
	while (x < len)
	{
		y = 0;
		while (y < len)
		{
			ft_putchar(tab[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
