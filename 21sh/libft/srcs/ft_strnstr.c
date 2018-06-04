/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:16:30 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 10:16:34 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	size_t	lo;

	j = 0;
	lo = ft_strlen(needle);
	if (lo == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[j] && len >= lo)
	{
		if (haystack[j] == needle[i])
		{
			if (ft_strncmp(haystack + j, needle, lo) == 0)
				return ((char *)haystack + j);
		}
		len--;
		j++;
	}
	return (NULL);
}
