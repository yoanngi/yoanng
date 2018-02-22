/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resolve.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 16:42:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 16:53:49 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

static char	**ft_malloc_tab(char **tab, int i, int nb)
{
	int j;

	j = 0;
	while (j != i)
	{
		if (!*tab[j] = (char *)malloc(sizeof(char) * nb + 1))
			return (NULL);
		j++;
	}
	return (tab);
}

int			ft_resolve(t_list *start, int i)
{
	t_list	*cpy;
	char	**tab_hash;

	cpy = start;
	if (!tab_hash = (char **)malloc(sizeof(char *) * i))
		return (0);
	tab_hash = ft_malloc_tab(tab_hash, i, 2);
	while (cpy)
	{
		ft_insert_data_in_tab(tab, &cpy);
		cpy = cpy->next;
	}
	return (1);
}
