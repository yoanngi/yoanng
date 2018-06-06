/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_del_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 09:38:44 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 15:38:59 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
**	Delete tab and return NULL
*/

char		**ft_del_tab(char **tab)
{
	int		i;

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

/*
**	Clean tab until int max and reposition tab
*/

char		**ft_del_tab_index(char **tab, int max)
{
	int		i;
	int		len;

	if (tab == NULL)
		return (NULL);
	i = 0;
	len = ft_len_tab(tab);
	while (i <= len)
	{
		if (max < len)
		{
			ft_strdel(&tab[i]);
			tab[i] = ft_strdup(tab[max]);
			ft_strdel(&tab[max]);
			max++;
		}
		else
			ft_strdel(&tab[i]);
		i++;
	}
	return (tab);
}
