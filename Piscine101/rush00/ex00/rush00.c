/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 18:37:32 by maxmarti          #+#    #+#             */
/*   Updated: 2017/09/11 21:24:37 by yoginet          ###   ########.fr       */
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
			if ((col == 1 && lin == 1) || ((col == x && lin == y) &&
		(col != 1 && lin != 1)))
				ft_putchar('o');
			else if ((col == 1 && lin == y) || (col == x && lin == 1))
				ft_putchar('o');
			else if ((lin == 1) || (lin == y))
				ft_putchar('-');
			else if ((col == 1) || (col == x))
				ft_putchar('|');
			else
				ft_putchar(' ');
			col++;
		}
		lin++;
		ft_putchar('\n');
	}
}
