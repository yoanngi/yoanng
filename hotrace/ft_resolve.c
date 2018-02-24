/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resolve.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 16:42:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 17:54:57 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

static void					ft_collision(t_lst *data, unsigned long **tab,
		int hash)
{
	t_lst					*cpy;

	cpy = (t_lst *)tab[hash][1] + 2;
	while (cpy->valeur)
		cpy = cpy->next;
	cpy->next = data;
}

unsigned long		**ft_insert(unsigned long **tab, t_lst *cpy)
{
	printf("here\n");
	if (tab[cpy->hash][0] == 0)
	{
		tab[cpy->hash][0] = cpy->hash;
		tab[cpy->hash][1] = (unsigned long long)&cpy;
	}
	else
		ft_collision(cpy, tab, cpy->hash);
	return (tab);
}

unsigned long				**ft_malloc_tab(unsigned long **tab, int i, int nb)
{
	int j;

	j = 0;
	while (j != i)
	{
		tab[j] = (unsigned long *)malloc(sizeof(unsigned long) * nb + 1);
		if (!tab[j])
			return (NULL);
		tab[j][0] = 0;
		tab[j][1] = 0;
		j++;
	}
	return (tab);
}

/*
int							ft_resolve(t_lst *start, int i)
{
	t_lst					*cpy;
	unsigned long			**tab;
	long					j;

	cpy = start;
	if (ft_check_long(i, start) == 1)
		return (1);
	i = 10000000;
	tab = (unsigned long **)malloc(sizeof(unsigned long long *) * i);
	if (!tab)
		return (0);
	ft_malloc_tab(tab, i, 2);
	j = cpy->hash;
	while (cpy)
	{
		tab = ft_insert(tab, cpy);
		cpy = cpy->next;
	}
	ft_whatdoyouwant(tab);
	return (1);
}*/
