/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 09:26:49 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/18 20:59:25 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_resolv(char **argv)
{
	int x;
	int y;
	int **tab;

	x = 0;
	tab = (int **)malloc(sizeof(int *) * 9);
	while (x < 9)
	{
		y = 0;
		tab[x] = (int *)malloc(sizeof(int *) * 9);
		while (y < 9)
		{
			if (argv[x + 1][y] == '.')
				tab[x][y] = 0;
			else if (argv[x + 1][y] >= '1' && argv[x + 1][y] <= '9')
				tab[x][y] = argv[x + 1][y] - 48;
			y++;
		}
		x++;
	}
	backtracking(tab, 0);
	ft_print_tab(tab);
}

void	ft_print_tab(int **tab)
{
	int x;
	int y;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			ft_putchar(tab[x][y] + 48);
			if (y != 8)
				ft_putchar(' ');
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
