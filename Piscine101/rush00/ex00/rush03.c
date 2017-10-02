/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 18:46:21 by maxmarti          #+#    #+#             */
/*   Updated: 2017/09/11 21:26:18 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int col;
	int lin;

	lin = 1;
	while (lin <= y && x > 0 && y > 0)
	{
		col = 1;
		while (col <= x)
		{
			if ((col == 1 && lin == 1) || (col == 1 && lin == y))
				ft_putchar('A');
			else if ((col == x && lin == 1) || (col == x && lin == y))
				ft_putchar('C');
			else if (lin == 1 || col == 1 || col == x || lin == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			col++;
		}
		lin++;
		ft_putchar('\n');
	}
}
