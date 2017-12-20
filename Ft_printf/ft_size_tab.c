/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_size_tab.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 13:51:29 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 13:54:44 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		**ft_size_tab(int nb)
{
	int		**tab;
	int		boucle;
	int		index;

	boucle = 0;
	index = 0;
	tab = (int **)malloc(sizeof(int *) * nb);
	while (boucle != 2)
	{
		*tab = (int *)malloc(sizeof(int) * 2);
		boucle++;
	}
	while (index != nb)
	{
		*tab[index] = index;
		index++;
	}
	return (tab);
}
