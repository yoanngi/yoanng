/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_remplissage_tab.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 15:34:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 13:40:42 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_remplissage_tab(char **tab, int i, char c)
{
	int pos;

	pos = 0;
	while (pos < i * i)
	{
		tab[pos / i][pos % i] = c;
		pos++;
	}
	return (tab);
}
