/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_place.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 15:05:30 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 14:38:04 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_ok(char **tab, int y, int x, int l)
{
	if (x < l && y < l)
		if (tab[y][x] == '.')
			return (1);
	return (0);
}

static void		remove_char(char **tab, char **tab_list, int l)
{
	char	c;
	int		p;

	p = 0;
	while (tab_list[0][p] == '.')
		p++;
	c = tab_list[0][p];
	p = 0;
	while (p < l * l)
	{
		if (tab[p / l][p % l] == c)
			tab[p / l][p % l] = '.';
		p++;
	}
}

static int		ft_copy(char **tab, char **tab_list, int pt, int l)
{
	int p;
	int c;

	c = 0;
	p = 0;
	while (p < 16)
	{
		if (tab_list[p / 4][p % 4] != '.' &&
				(tab_list[p / 4][p % 4] != '\0'))
			if (ft_ok(tab, (pt / l) + (p / 4),
						(pt % l) + (p % 4), l) == 1)
			{
				tab[(pt / l) + (p / 4)][(pt % l) + (p % 4)] =
	tab_list[p / 4][p % 4];
				c++;
			}
		p++;
	}
	if (c == 4)
		return (1);
	return (0);
}

int				ft_place_one(char **tab, t_list *lst, int l, int p)
{
	if (lst == NULL)
		return (1);
	while (p < l * l)
	{
		if (tab[p / l][p % l] == '.')
		{
			if (ft_copy(tab, lst->block, p, l) == 1)
			{
				if (ft_place_one(tab, lst->next, l, 0))
					return (1);
			}
			remove_char(tab, lst->block, l);
		}
		p++;
	}
	return (0);
}
