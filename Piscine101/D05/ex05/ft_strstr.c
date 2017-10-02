/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 17:13:17 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/21 08:48:17 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int lo;
	int cmp;

	i = 0;
	j = 0;
	while (to_find[i])
		i++;
	lo = i;
	while (str[j])
	{
		cmp = 0;
		i = 0;
		if (str[j] == to_find[i])
			while (str[j + i] == to_find[i] && i < lo)
			{
				i++;
				cmp++;
			}
		if (cmp == lo)
			return (str + j);
		j++;
	}
	return (NULL);
}
