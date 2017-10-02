/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 08:27:27 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/19 14:29:07 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		main(int argc, char **argv)
{
	int i;
	int j;
	int max;

	i = 1;
	j = 0;
	if (argc != 10)
		max = -150;
	while (argc != 1)
	{
		j = ft_check_sudoku(argv[i]);
		max += ft_check_max(argv[i]);
		argc--;
		i++;
		if (j == 1)
			max += -150;
	}
	if (max < 17)
	{
		ft_putstr("Error\n");
		return (0);
	}
	ft_resolv(argv);
	return (0);
}
