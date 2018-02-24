/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc_tab.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/24 12:57:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/24 13:04:17 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

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
