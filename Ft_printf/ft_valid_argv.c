/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_valid_argv.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 13:07:01 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 11:55:26 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid_inverse(char c)
{
	char	*valid;
	int		i;

	valid = "sSpdDioOuUxXcCljz";
	i = 0;
	while (i != 17)
	{
		if (c == valid[i])
			return (1);
		i++;
	}
	return (0);
}

void		ft_valid_argv(char **tab, s_struct *data)
{
	char	*cpy;
	int		j;
	int		x;

	j = 0;
	while (j != data->argc)
	{
		cpy = ft_strdup(tab[j]);
		x = ft_strlen(cpy);
		while (x != 0)
		{
			if (ft_valid_inverse(cpy[x]) == 0)
				x--;
			else
			{
				tab[j] = ft_strsub(cpy, 0, x + 1);
				x = 0;
			}
		}
		ft_strdel(&cpy);
		j++;
	}
	data->argv = tab;
}
