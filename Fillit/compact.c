/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compact.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 12:35:04 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 11:10:38 by yoginet     ###    #+. /#+    ###.fr     */
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

t_list		*ft_compact(t_list *s)
{
	t_list	*chaine;

	chaine = s;
	while (s)
	{
		s->block = compact_ligne(s->block);
		s->block = compact_col(s->block);
		s = s->next;
	}
	return (chaine);
}
