/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yginet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:54:50 by yginet            #+#    #+#             */
/*   Updated: 2017/03/27 18:54:53 by yginet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	f;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
	{
		f = ft_recursive_factorial(nb - 1);
		if ((nb * f) / nb != f)
			return (0);
		return (nb * f);
	}
}
