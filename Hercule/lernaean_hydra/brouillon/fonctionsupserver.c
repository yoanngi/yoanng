/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fonctionsupserver.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 13:43:47 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 15:13:45 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "server.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		((char*)s)[i] = '\0';
		i++;
	}
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strnew(size_t size)
{
	char	*mal;

	mal = (char *)malloc(sizeof(char) * (size + 1));
	if (!mal)
		return (NULL);
	ft_memset(mal, '\0', size + 1);
	return (mal);
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *chaine;

	chaine = (unsigned char*)str;
	while (n > 0)
	{
		*chaine++ = (unsigned char)c;
		n--;
	}
	return (str);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		else if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
