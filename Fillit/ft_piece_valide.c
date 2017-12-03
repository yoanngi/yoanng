/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_piece_valide.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 14:39:24 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 14:43:11 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_piece_valide(char **s, int pos)
{
	int	nb;

	nb = 0;
	if (pos < 16)
		return (1);
	while (s[pos / 4][pos % 4] != '#')
		pos++;
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
	if (nb == 0)
		return (0);
	else
		return (ft_piece_valide(s, pos + 1));
}
