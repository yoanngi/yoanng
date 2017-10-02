/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 18:38:40 by maxmarti          #+#    #+#             */
/*   Updated: 2017/09/11 21:25:55 by yoginet          ###   ########.fr       */
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
			if ((col == 1 && lin == 1) || (col == x && lin == 1))
				ft_putchar('A');
			else if ((col == 1 && lin == y) || (col == x && lin == y))
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
