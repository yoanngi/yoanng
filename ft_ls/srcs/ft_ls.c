/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 10:02:47 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_initialise_struct(s_struct **data, int nb, char **params)
{
	(*data)->tiret = 0;
	(*data)->rmaj = 0;
	(*data)->rmin = 0;
	(*data)->amin = 0;
	(*data)->tmin = 0;
	(*data)->lmin = 0;
	(*data)->invalid = 0;
	(*data)->nb_file = ft_count_files_valid(nb, params);
	(*data)->multifile = (char **)malloc(sizeof(char *) *
			((*data)->nb_file + 1));
}

static char		**ft_range_tab(char **tab, int len, int i)
{
	char	*tmp;
	int		start;

	start = i;
	while (i != len - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0 && i + 1 <= len)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = start;
		}
		else
			i++;
	}
	return (tab);
}

int				ft_how_to_treat(int ac, char **av, int i, s_struct **data)
{
	ft_range_tab(av, ac, i);
	ft_ls_two(i, ac, av, data);
	return (0);
}

void			ft_ls_two(int i, int nb, char **params, s_struct **data)
{
	int dir;

	dir = 0;
	while (i != nb)
	{
		if (ft_file_exist(params[i], 1) == 1)
		{
			(*data)->multifile[dir] = ft_strdup(params[i]);
			dir++;
		}
		else
		{
			(*data)->invalid = 1;
			basic_error(params[i]);
		}
		i++;
	}
}

void			ft_ls(char **params, int nb, int end)
{
	s_struct	*data;
	int			i;

	data = (s_struct *)malloc(sizeof(s_struct));
	i = 1;
	ft_initialise_struct(&data, nb, params);
	while (end == 0)
	{
		if (params[i][0] == '-')
		{
			if (ft_option_exist(params[i], 1) == 1)
			{
				ft_insert_valid_option(params[i], &data);
			}
		}
		else
		{
			ft_how_to_treat(nb, params, i, &data);
			end = 1;
		}
		i++;
		if (i == nb)
			end = 1;
	}
	ft_check_options(data);
}
