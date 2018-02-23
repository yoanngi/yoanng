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

static void		ft_insert_data_in_tab(void ***tab, t_lst *cpy)
{
	if (tab[cpy->hash][0] == (long)0)
	{
		tab[cpy->hash][0] = (long)cpy->hash;
		tab[cpy->hash][1] = &cpy;
		printf("Valeur tab[0][0] = %ld\n", (long)tab[0][0]);
		printf("Valeur tab[0][1]= %p\n", tab[0][1]);
	}
	else
		printf("tab[cpy->hash][0] est deja pris !\n");
//		creer liste chainer
}

static void		**ft_malloc_tab(void **tab, int i, int nb)
{
	int j;

	j = 0;
	while (j != i)
	{
		tab[j] = (void *)malloc(sizeof(void) * nb + 1);
		if (!tab[j])
			return (NULL);
		tab[j] = (long)0;
		j++;
	}
	return (tab);
}

int				ft_resolve(t_lst *start, int i)
{
	t_lst	*cpy;
	void	**tab_hash;

	int j = 0;
	cpy = start;
	tab_hash = (void **)malloc(sizeof(void *) * i);
	if (!tab_hash)
		return (0);
	tab_hash = ft_malloc_tab(tab_hash, i, 2);
	while (cpy)
	{
		printf("cpy->cle = %s, cpy->valeur = %s\n", cpy->cle, cpy->valeur);
		cpy->hash = j;
		j++;
		ft_insert_data_in_tab(&tab_hash, cpy);
		cpy = cpy->next;
	}
	return (1);
}
