/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 12:17:41 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/20 14:17:30 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int bn;

	bn = nb;
	nb -= 1;
	if (nb < 2)
		return (0);
	if (nb = 2)
		return (1);
	while (nb != 2)
	{
		if ((bn % nb) == 0)
			return (0);
		nb--;
	}
	return (1);
}
