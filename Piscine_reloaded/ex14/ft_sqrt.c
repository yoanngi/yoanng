/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yginet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:55:32 by yginet            #+#    #+#             */
/*   Updated: 2017/03/27 19:00:18 by yginet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_sqrt(int nb)
{
	int ope;

	ope = 1;
	if (nb < 0)
		return (0);
	while ((ope * ope) < nb)
		ope++;
	return (((ope * ope) == nb) ? ope : 0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

int		main(void)
{
	int nb;

	nb = ft_sqrt(16);
	ft_putnbr(nb);
	return (0);
}
