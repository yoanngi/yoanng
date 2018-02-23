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

static void		**ft_insert_data_in_tab(void ***tab, t_lst *cpy)
{
	printf("i||||||||cpy->cle = %s, cpy->valeur = %s, cpy->hash = %ld\n", cpy->cle, cpy->valeur, cpy->hash);
	if (tab[cpy->hash][0] != NULL)
	{
		tab[cpy->hash][0] = cpy->hash;
		tab[cpy->hash][1] = &cpy;
		printf("Valeur tab[0][0] = %ld\n", (long)tab[0][0]);
		printf("Valeur tab[0][1]= %p\n", tab[0][1]);
	}
	else
		printf("tab[cpy->hash][0] est deja pris !\n");
//		creer liste chainer
	return (*tab);
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
		tab[j] = NULL;
		j++;
	}
	return (*tab);
}

int				ft_resolve(t_lst *start, int i)
{
	t_lst	*cpy;
	void	**tab_hash;

	long j = 1;
	cpy = start;
	tab_hash = (void **)malloc(sizeof(void *) * i);
	if (!tab_hash)
		return (0);
	ft_malloc_tab(tab_hash, i, 2);
	while (cpy)
	{
		cpy->hash = j;
		printf("cpy->cle = %s, cpy->valeur = %s, cpy->hash = %ld\n", cpy->cle, cpy->valeur, cpy->hash);
		j++;
		tab_hash = ft_insert_data_in_tab(&tab_hash, cpy);
		cpy = cpy->next;
	}
	return (1);
}
