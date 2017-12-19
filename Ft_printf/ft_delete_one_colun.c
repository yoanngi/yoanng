/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_delete_one_colun.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/19 10:39:35 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 10:56:09 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_delete_one_colun(char **tab, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		tab[i] = ft_strdup(tab[i + 1]);
		i++;
	}
	tab[len] = ft_strdup("");
	return (tab);
}
