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

char	**ft_size_tab(int nb)
{
	char	**tab;
	int		boucle;
	int		index;

	boucle = 0;
	index = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	while (boucle != nb)
	{
		if (!(tab[boucle] = (char *)malloc(sizeof(char) * 3)))
			return (NULL);
		boucle++;
	}
	while (index != nb)
	{
		*tab[index] = index;
		index++;
	}
	return (tab);
}
