/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:00:38 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/21 08:55:19 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int x;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	x = i;
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	j = 0;
	while (src[j])
		j++;
	dest[i] = '\0';
	if (x < size)
		return (j + x);
	else
		return (j + size);
}
