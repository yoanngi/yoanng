/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_valid_argv.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 13:07:01 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 15:22:52 by yoginet     ###    #+. /#+    ###.fr     */
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

static char	ft_resize(char *cpy, int len)
{
	char *str;

	str = ft_strdup(cpy);
	cpy = ft_strsub(str, 0, len);
	ft_strdel(&str);
	return (*cpy);
}

void		ft_valid_argv(char **tab, s_struct *data)
{
	char	*cpy;
	int		j;
	int		x;
	int		y;

	j = 0;
	y = 0;
	while (j != data->argc)
	{
		cpy = ft_strdup(tab[j]);
		x = ft_strlen(cpy);
		while (x != 0)
		{
			if (ft_valid_inverse(cpy[x]) == 1)
				y++;
			else
				ft_resize(cpy, y);
			x--;
		}
		tab[j] = ft_strsub(cpy, 0, y + 1);
		printf("%s\n", tab[j]);
		ft_strdel(&cpy);
		j++;
	}
	data->argv = tab;;
}
