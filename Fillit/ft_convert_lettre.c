/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_lettre.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 14:40:49 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 14:40:55 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_convert_lettre(char **s, char c)
{
	int pos;

	pos = 0;
	while (pos < 16)
	{
		if (s[pos / 4][pos % 4] == '#')
			s[pos / 4][pos % 4] = c;
		pos++;
	}
}
