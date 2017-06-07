/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yginet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:23:44 by yginet            #+#    #+#             */
/*   Updated: 2017/03/28 12:23:46 by yginet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ar;

	if (min >= max)
		return (0);
	ar = malloc(sizeof(int) * (max - min + 1));
	if (!ar)
		return (0);
	i = 0;
	while (min < max)
		ar[i++] = min++;
	return (ar);
}
