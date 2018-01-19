/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:15:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 10:15:16 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	j;
	char	*new_s;

	if (s == 0)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	new_s = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_s)
		return (NULL);
	while (s[j])
	{
		new_s[j] = f(j, s[j]);
		j++;
	}
	new_s[i] = '\0';
	return (new_s);
}
