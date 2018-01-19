/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:14:42 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 10:14:43 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	x = i;
	while (src[j] && (i + 1) < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	j = 0;
	while (src[j])
		j++;
	dst[i] = '\0';
	if (x < dstsize)
		return (j + x);
	else
		return (j + dstsize);
}
