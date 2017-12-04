/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_comptact_unit.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 11:11:06 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 14:47:43 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_switch_ligne(char **s)
{
	char	*temp;
	int		i;

	i = 0;
	while (i < 3)
	{
		temp = s[i];
		s[i] = s[i + 1];
		s[i + 1] = temp;
		i++;
	}
	return (s);
}

static char	**compact_ligne(char **s)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (i < 4)
	{
		if (s[0][i] == '#')
			c++;
		i++;
	}
	if (c == 0)
	{
		s = ft_switch_ligne(s);
		compact_ligne(s);
	}
	return (s);
}

static char	**ft_switch_col(char **s)
{
	char	temp;
	int		i;
	int		j;

	j = 0;
	while (j < 3)
	{
		i = 0;
		while (i < 4)
		{
			temp = s[i][j];
			s[i][j] = s[i][j + 1];
			s[i][j + 1] = temp;
			i++;
		}
		j++;
	}
	return (s);
}

static char	**compact_col(char **s)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (i < 4)
	{
		if (s[i][0] == '#')
			c++;
		i++;
	}
	if (c == 0)
	{
		s = ft_switch_col(s);
		compact_col(s);
	}
	return (s);
}

void		ft_compact_unit(const char *s)
{
	char	**tab;
	int		pos;

	pos = 0;
	tab = NULL;
	tab = ft_malloc_tab(tab, 4);
	tab = ft_strsplit(s, '\n');
	tab = compact_ligne(tab);
	tab = compact_col(tab);
	if (ft_piece_valide(tab, 0) == 0)
		ft_putstr("error\n");
	else
	{
		ft_convert_lettre(tab, 'A');
		ft_print_carre(tab, 4);
	}
	free(tab);
}
