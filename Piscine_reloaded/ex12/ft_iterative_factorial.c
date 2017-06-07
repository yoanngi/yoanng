/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yginet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:54:01 by yginet            #+#    #+#             */
/*   Updated: 2017/03/27 18:54:08 by yginet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	f;
	int	fn;

	i = 1;
	f = 1;
	fn = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		fn = f * i;
		if (fn / i != f)
			return (0);
		i++;
		f = fn;
	}
	return (f);
}
