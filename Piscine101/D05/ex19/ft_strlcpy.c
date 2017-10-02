/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:06:00 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/19 21:21:30 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int j;
	unsigned int i;

	j = 0;
	i = 0;
	while (src[j])
		j++;
	if (size == 0)
		return (0);
	while (i + 1 < size)
	{
		if (src[i] == '\0')
			dest[i] = '\0';
		else if (src[i] != '\0')
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}
