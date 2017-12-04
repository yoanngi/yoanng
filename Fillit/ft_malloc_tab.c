/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc_tab.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:50:42 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 11:03:06 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_malloc_tab(char **tab, int len)
{
	int	i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * len);
	while (i < len)
	{
		tab[i] = (char *)malloc(sizeof(char) * len);
		i++;
	}
	return (tab);
}
