/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_word.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:05:46 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 10:19:29 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_count_word(const char *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (j);
}
