/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo_tetra.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 15:50:47 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 13:12:09 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_remplissage(t_list *lst, char **tab, int len, int p)
{
	t_list	*new;
	char	**tabcpy;

	new = lst;
	tabcpy = NULL;
	tab = ft_malloc_tab(tab, len);
	ft_remplissage_tab(tab, len, '.');
	while (lst)
	{
		if (ft_place_one(tab, lst, len, p) == 1)
		{
			ft_print_carre(tab, len);
			return (tab);
		}
		else
		{
			free(tab);
			return (ft_remplissage(new, tabcpy, len + 1, 0));
		}
	}
	return (tab);
}

void			ft_algo_tetra(t_list *lst, int i)
{
	char	**tab;
	int		pos;

	pos = 0;
	tab = ft_remplissage(lst, tab, i, pos);
	free(tab);
}
