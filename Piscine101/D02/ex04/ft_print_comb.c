/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:04:45 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/08 19:45:28 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_imp(int a, int b, int c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if ((a == '7') && (b == '8') && (c == '9'))
		return (0);
	else
	{
		ft_putchar(',');
		ft_putchar(' ');
		return (0);
	}
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = 48;
	b = 48;
	c = 48;
	while (a != 56)
	{
		while (b != 58)
		{
			while ((c != 58) && ((a != b) && (b != c) && (a != c)))
			{
				ft_imp(a, b, c);
				c++;
			}
			b++;
			c = b + 1;
		}
		a++;
		b = a + 1;
		c = b + 1;
	}
}
