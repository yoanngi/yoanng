/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 14:18:46 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/24 14:21:53 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

int		main(void)
{
	unsigned long	**tab;
	int				i;

	i = 10000000;
	tab = (unsigned long **)malloc(sizeof(unsigned long *) * i);
	if (!tab)
		return (1);
	ft_malloc_tab(tab, i, 2);
	ft_recupere_infos(tab);
	return (0);
}
