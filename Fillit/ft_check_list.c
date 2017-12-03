/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_list.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 13:31:23 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 14:42:43 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	ft_check_tab(char *content)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (content[i])
	{
		if (content[i] == '#')
			nb++;
		i++;
	}
	if (nb != 4)
		return (0);
	else
		return (1);
}

static int	ft_compare_fs(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		if (ft_check_tab(lst->content) == 0)
			return (0);
		if (ft_piece_valide(lst->block, 0) == 0)
			return (0);
		ft_convert_lettre(lst->block, ('A' + i));
		lst = lst->next;
		i++;
	}
	return (1);
}

void		ft_check_list(t_list *lst)
{
	t_list	*new;
	t_list	*new2;
	t_list	*new3;
	int		i;
	int		j;

	new = lst;
	new2 = lst;
	new3 = lst;
	i = 0;
	j = 1;
	while (lst)
	{
		lst->block = ft_strsplit(lst->content, '\n');
		lst = lst->next;
		i++;
	}
	while (j * j <= (4 * (i - 1)))
		j++;
	ft_compact(new);
	if (ft_compare_fs(new2) == 1)
		ft_algo_tetra(new3, j);
	else
		ft_putstr("error\n");
}
