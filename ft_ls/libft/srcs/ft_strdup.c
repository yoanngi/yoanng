/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:13:35 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 10:13:37 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	i;
	size_t	len_str;

	len_str = ft_strlen(s1);
	new = (char *)malloc(sizeof(char) * (len_str + 1));
	if (!new)
		return (NULL);
	i = 0;
	while ((s1[i] != '\0') && (i < len_str))
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
