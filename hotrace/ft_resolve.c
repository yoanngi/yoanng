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
#include <stdio.h>

static void	ft_insert_data_in_tab(char **tab, t_lst **cpy)
{
	if (tab[(*cpy)->hash][0] == 0)
	{
		tab[(*cpy)->hash][0] = (*cpy)->hash;
		tab[(*cpy)->hash][1] = *(&cpy);
	}
//	else
//		creer liste chainer
}

static char	**ft_malloc_tab(char **tab, int i, int nb)
{
	int j;

	j = 0;
	while (j != i)
	{
		tab[j] = (char *)malloc(sizeof(char) * nb + 1);
		if (!tab[j])
			return (NULL);
		tab[j] = 0;
		j++;
	}
	return (tab);
}

int			ft_resolve(t_lst *start, int i)
{
	t_lst	*cpy;
	char	**tab_hash;

	cpy = start;
	tab_hash = (char **)malloc(sizeof(char *) * i);
	if (!tab_hash)
		return (0);
	tab_hash = ft_malloc_tab(tab_hash, i, 2);
	while (cpy)
	{
		ft_insert_data_in_tab(tab_hash, &cpy);
		cpy = cpy->next;
	}
	printf("test\n");
	printf("tab = %s\n", tab_hash[0]);
	return (1);
}
