/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resolve.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 16:42:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 12:07:35 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdio.h>

static void		ft_collision(t_lst *data, char **tab, long index)
{
	t_lst *new;
	t_lst *cpy;

	cpy = tab[index][1];
	cpy->collision = ft_list_new();
	cpy = cpy->collision;
	new = cpy;
	new->cle = data->cle;
	new->valeur = data->valeur;
}

static long		**ft_insert_data_in_tab(long **tab, t_lst *cpy)
{
	if (tab[cpy->hash][0] == 0)
	{
		tab[cpy->hash][0] = cpy->hash;
		tab[cpy->hash][1] = (long)&cpy->next;
		printf("Valeur tab[%ld][0] = %ld\n", cpy->hash, tab[cpy->hash][0]);
		printf("Valeur tab[%ld][1]= %ld\n", cpy->hash, tab[cpy->hash][1]);
		printf("hexa: %lx\n", tab[cpy->hash][1]);
	}
	else
	{
		printf("Collision !\n");
		//ft_collision(cpy, tab, cpy->hash);
	}
	return (tab);
}

static long		**ft_malloc_tab(long **tab, int i, int nb)
{
	int j;

	j = 0;
	while (j != i)
	{
		tab[j] = (long *)malloc(sizeof(long) * nb + 1);
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
	long	**tab;

	long j = 1;
	cpy = start;
	i = 100000;
	tab = (long **)malloc(sizeof(long *) * i);
	if (!tab)
		return (0);
	ft_malloc_tab(tab, i, 2);
	while (cpy)
	{
		tab = ft_insert_data_in_tab(tab, cpy);
		printf("adresse cpy->next : %p\n", &cpy->next);
		cpy = cpy->next;
		j++;
	}
	return (1);
}
