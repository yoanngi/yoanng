/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:18:50 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/12 14:34:12 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int result;

	result = nb;
	if (power < 0)
		return (result = 0);
	if (power == 0)
		return (result = 1);
	while ((power - 1) != 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
