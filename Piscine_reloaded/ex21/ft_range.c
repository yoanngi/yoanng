/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:09:10 by yoginet           #+#    #+#             */
/*   Updated: 2017/11/10 10:09:14 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_long_tab(int min, int max)
{
	int len;

	len = 0;
	while (min < max)
	{
		len++;
		min++;
	}
	return (len);
}

int		*ft_range(int min, int max)
{
	int len;
	int *tab;
	int i;

	i = 0;
	if (min >= max)
		return (NULL);
	len = ft_long_tab(min, max);
	tab = (int*)malloc(sizeof(int) * len);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
