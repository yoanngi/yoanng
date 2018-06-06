/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_tab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/26 11:42:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 15:43:28 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		ft_print_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}
