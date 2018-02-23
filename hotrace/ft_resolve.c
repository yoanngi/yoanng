/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resolve.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 16:42:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 15:39:26 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

static void		ft_collision(t_lst *data, unsigned long long **tab, int hash)
{
	t_lst *cpy;

	cpy = (t_lst *)tab[hash][1] + 2;
	while (cpy)
		cpy = cpy->next;
	cpy->next = data;
}

static unsigned long long		**ft_insert_data_in_tab(unsigned long long **tab, t_lst *cpy)
{
	if (tab[cpy->hash][0] == 0)
	{
		tab[cpy->hash][0] = cpy->hash;
		tab[cpy->hash][1] = (unsigned long long)&cpy;
//		printf("Valeur tab[%ld][0] = %lld\n", cpy->hash, tab[cpy->hash][0]);
//		printf("Valeur tab[%ld][1]= %lld\n", cpy->hash, tab[cpy->hash][1]);
//		printf("Adress: %p\n", &cpy);
//		printf("Adress->next: %p\n", &cpy->next);
	}
	else
	{
		printf("Collision !\n");
		ft_collision(cpy, tab, cpy->hash);
	}
	return (tab);
}

static unsigned long long		**ft_malloc_tab(unsigned long long **tab, int i, int nb)
{
	int j;

	j = 0;
	while (j != i)
	{
		tab[j] = (unsigned long long *)malloc(sizeof(unsigned long long) * nb + 1);
		if (!tab[j])
			return (NULL);
		tab[j][0] = 0;
		tab[j][1] = 0;
		j++;
	}
	return (tab);
}

int				ft_resolve(t_lst *start, int i)
{
	t_lst	*cpy;
	unsigned long long	**tab;

	long	j;
	cpy = start;
	i = 10000000;
	tab = (unsigned long long **)malloc(sizeof(unsigned long long *) * i);
	if (!tab)
		return (0);
	ft_malloc_tab(tab, i, 2);
	j = cpy->hash;
	while (cpy)
	{
		tab = ft_insert_data_in_tab(tab, cpy);
		cpy = cpy->next;
	}
	ft_whatdoyouwant(tab);
	ft_test_acces(tab, j);
	return (1);
}
