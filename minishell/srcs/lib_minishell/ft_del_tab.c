/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_del_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 09:38:44 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 09:38:49 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Delete tab and return NULL
*/

char		*ft_del_tab(char **tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		return (NULL);
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}
