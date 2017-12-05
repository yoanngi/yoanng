/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo_tetra.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:59:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 09:42:04 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_del_lst(t_list *lst)
{
	while (lst)
	{
		free(lst->block);
		free(lst->content);
		free(lst);
		lst = lst->next;
	}
}

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
	t_list	*remove;
	char	**tab;
	int		pos;

	remove = lst;
	pos = 0;
	tab = NULL;
	tab = ft_remplissage(lst, tab, i, pos);
	free(tab);
	ft_del_lst(remove);
}
