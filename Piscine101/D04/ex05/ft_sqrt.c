/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:16:55 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/14 15:19:42 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;
	int c;

	i = 2;
	c = 0;
	while (i <= nb / 2 + 1)
	{
		c = i * i;
		if (c == nb)
			return (i);
		else
			i++;
	}
	return (0);
}
