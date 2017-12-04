/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_piece_valide.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 14:39:24 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 13:39:50 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_piece_valide(char **s, int pos)
{
	int	nb;

	nb = 0;
	while (pos < 16)
	{
		if (s[pos / 4][pos % 4] == '#')
		{
			if (pos % 4 < 3)
				if (s[pos / 4][(pos % 4) + 1] == '#')
					nb++;
			if (pos % 4 > 0)
				if (s[pos / 4][(pos % 4) - 1] == '#')
					nb++;
			if (pos / 4 < 3)
				if (s[(pos / 4) + 1][pos % 4] == '#')
					nb++;
			if (pos / 4 > 0)
				if (s[(pos / 4) - 1][pos % 4] == '#')
					nb++;
		}
		pos++;
	}
	if (nb < 6)
		return (0);
	return (1);
}
