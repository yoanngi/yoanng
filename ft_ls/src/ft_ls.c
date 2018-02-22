/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 13:25:10 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"


static int		ft_option_exist(char *str, int nb)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == ' ' || str[i] == 'R' || str[i] == 'r' ||
			str[i] == 'l' || str[i] == 't' || str[i] == 'a')
		i++;
	if (nb == 1 && (size_t)i != ft_strlen(str))
	{
		ft_error(str[i]);
		return (0);
	}
	if ((size_t)i != ft_strlen(str))
		return (0);
	return (1);
}

static void		ft_insert_valid_option(char *cmp, s_struct **data)
{
	int i;

	i = 0;
	while (cmp[i])
	{
		if (cmp[i] == '-')
			(*data)->tiret = 1;
		else if (cmp[i] == 'R')
			(*data)->rmaj = 1;
		else if (cmp[i] == 'r')
			(*data)->rmin = 1;
		else if (cmp[i] == 'a')
			(*data)->amin = 1;
		else if (cmp[i] == 't')
			(*data)->tmin = 1;
		else if (cmp[i] == 'l')
			(*data)->lmin = 1;
		i++;
	}
}

static int		ft_count_files_valid(int argc, char **argv)
{
	char	*cpy;
	int		i;
	int		nb;
	int		tmp;

	i = 0;
	nb = 0;
	tmp = argc;
	while (i != (argc - 1))
	{
		cpy = ft_strdup(argv[tmp - 1]);
		if (ft_file_exist_malloc(cpy) == 1)
			nb += 1;
		ft_strdel(&cpy);
		i++;
		tmp--;
	}
	return (nb);
}

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
	if ((*data)->nb_file == 0)
	{
		(*data)->multifile[0] = ft_strdup(".");
		(*data)->nb_file = 1;
	}
}

static void		ft_ls_two(int i, int nb, char **params, s_struct **data)
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
				ft_insert_valid_option(params[i], &data);
		}
		else
		{
			ft_ls_two(i, nb, params, &data);
			end = 1;
		}
		i++;
		if (i == nb - 1)
			end = 1;
	}
	ft_check_options(data);
}
