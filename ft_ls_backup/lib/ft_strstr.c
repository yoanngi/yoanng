/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:17:08 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 10:17:08 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	lo;

	j = 0;
	lo = ft_strlen(needle);
	if ((needle == '\0' && haystack == '\0') || lo == 0)
		return ((char *)haystack);
	while (haystack[j])
	{
		i = 0;
		if (haystack[j] == needle[i])
		{
			while (haystack[j + i] == needle[i] && i < lo)
				i++;
			if (lo == i)
				return ((char *)haystack + j);
		}
		j++;
	}
	return (NULL);
}
