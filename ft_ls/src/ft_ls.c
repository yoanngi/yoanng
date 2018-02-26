/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 11:06:49 by yoginet     ###    #+. /#+    ###.fr     */
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
	(*data)->invalid = NULL;
	(*data)->nb_file = ft_count_files_valid(nb, params);
	(*data)->multifile = (char **)malloc(sizeof(char *) *
			((*data)->nb_file + 1));
}

int				ft_how_to_treat(int ac, char **av, int i, s_struct **data)
{
	int j;

	j = ac;
	while (j-- && j != i)
	{
		if (av[j - 1][0] == '-')
		{
			ft_ls_two(i, ac, av, data);
			return (0);
		}
	}
	ft_ls_two_inverse(i, ac, av, data);
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
			basic_error(params[i]);
		i++;
	}
}

void			ft_ls_two_inverse(int i, int nb, char **params, s_struct **data)
{
	int dir;

	dir = 0;
	while (nb != i)
	{
		if (ft_file_exist(params[nb - 1], 1) == 1)
		{
			(*data)->multifile[dir] = ft_strdup(params[nb - 1]);
			dir++;
		}
		else
			basic_error(params[nb - 1]);
		nb--;
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
