/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_place.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 15:05:30 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 13:40:04 by kcabus      ###    #+. /#+    ###.fr     */
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
	int		pos;

	pos = 0;
	while (tab_list[0][pos] == '.')
		pos++;
	c = tab_list[0][pos];
	pos = 0;
	while (pos < l * l)
	{
		if (tab[pos / l][pos % l] == c)
			tab[pos / l][pos % l] = '.';
		pos++;
	}
}

static int		ft_copy(char **tab, char **tab_list, int pt, int l)
{
	int pl;
	int c;

	c = 0;
	pl = 0;
	while (pl < 16)
	{
		if (tab_list[pl / 4][pl % 4] != '.' &&
				(tab_list[pl / 4][pl % 4] != '\0'))
			if (ft_ok(tab, (pt / l) + (pl / 4),
						(pt % l) + (pl % 4), l) == 1)
			{
				tab[(pt / l) + (pl / 4)][(pt % l) + (pl % 4)] =
					tab_list[pl / 4][pl % 4];
				c++;
			}
		pl++;
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
		if (ft_copy(tab, lst->block, p, l) == 1)
			if (ft_place_one(tab, lst->next, l, 0))
				return (1);
		remove_char(tab, lst->block, l);
		p++;
	}
	return (0);
}
