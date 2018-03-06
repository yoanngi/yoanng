/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:17:28 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 13:21:51 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int	ft_check_behind(const char *s)
{
	size_t j;
	size_t i;

	j = ft_strlen(s) - 1;
	i = ft_strlen(s);
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	return (i - j);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	x;
	size_t	y;

	if (s == NULL)
		return (NULL);
	i = ft_check(s);
	x = ft_check_behind(s);
	y = ft_strlen(s);
	if (i == y)
	{
		new = (char *)malloc(sizeof(char) * 1);
		if (new == NULL)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	new = ft_strsub((const char *)s, i, (1 + y - (i + x)));
	return (new);
}
