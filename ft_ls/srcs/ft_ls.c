/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 13:57:54 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_initialise_struct(t_struct **data, int nb, char **params)
{
	(*data)->tiret = 0;
	(*data)->rmaj = 0;
	(*data)->rmin = 0;
	(*data)->amin = 0;
	(*data)->tmin = 0;
	(*data)->lmin = 0;
	(*data)->invalid = 0;
	(*data)->just_file = 0;
	(*data)->nb_file = ft_count_files_valid(nb, params);
	(*data)->multifile = (char **)malloc(sizeof(char *) *
			((*data)->nb_file + 1));
}

static char		**ft_range_tab(char **tab, int len, int i)
{
	char	*tmp;
	int		start;

	start = i;
	tmp = NULL;
	while (i != len - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0 && i + 1 <= len)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			ft_strdel(&tmp);
			i = start;
		}
		else
			i++;
	}
	return (tab);
}

int				ft_to_treat(int ac, char **av, int i, t_struct **da)
{
	ft_range_tab(av, ac, i);
	ft_ls_two(i, ac, av, da);
	return (0);
}

void			ft_ls_two(int i, int nb, char **params, t_struct **da)
{
	int		dir;
	char	*tmp;

	dir = 0;
	tmp = NULL;
	while (i != nb)
	{
		tmp = ft_strdup(params[i]);
		if (ft_access_or_not(&tmp) == 1)
		{
			(*da)->multifile[dir] = ft_strdup(tmp);
			dir++;
		}
		else if (ft_is_file(&tmp, *da) == 0)
		{
			(*da)->invalid = 1;
			basic_error(params[i]);
		}
		ft_strdel(&tmp);
		i++;
	}
}

void			ft_ls(char **params, int nb, int end)
{
	t_struct	*data;
	int			i;

	data = (t_struct *)malloc(sizeof(t_struct));
	i = 1;
	ft_initialise_struct(&data, nb, params);
	while (end == 0)
	{
		if (params[i][0] == '-' && ft_strlen(params[i]) > 1)
		{
			if (ft_option_exist(params[i], 1) == 1)
				ft_insert_valid_option(params[i], &data);
		}
		else
		{
			ft_to_treat(nb, params, i, &data);
			end = 1;
		}
		i++;
		if (i == nb)
			end = 1;
	}
	ft_check_options(data);
	ft_del_struct(data, params);
}
