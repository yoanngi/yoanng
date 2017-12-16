/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:16:59 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 13:19:30 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len_word(const char *s, size_t index, char c)
{
	size_t j;

	j = 0;
	while (s[index] != c && s[index] != '\0')
	{
		index++;
		j++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	nb_mot;
	size_t	i;
	size_t	j;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	nb_mot = ft_count_word(s, c);
	tab = (char **)malloc(sizeof(char *) * nb_mot + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (nb_mot--)
	{
		while (s[i] == c && i < len)
			i++;
		tab[j++] = ft_strsub(s, i, ft_len_word(s, i, c));
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
