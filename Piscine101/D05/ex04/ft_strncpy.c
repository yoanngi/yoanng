/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 17:09:44 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/21 08:34:16 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (dest);
	while (i < n)
	{
		if (src[i] == '\0')
			dest[i] = '\0';
		else if (src[i] != '\0')
			dest[i] = src[i];
		i++;
	}
	return (dest);
}
