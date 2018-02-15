/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fonctionsupserver.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 13:43:47 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 15:50:44 by yoginet     ###    #+. /#+    ###.fr     */
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
		((char*)s)[i] = 0;
		i++;
	}
}

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
