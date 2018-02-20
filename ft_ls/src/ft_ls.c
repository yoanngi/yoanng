/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 15:17:32 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_is_option_valid(char *str)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == ' ' || str[i] == 'R' || str[i] == 'r' ||
	str[i] == 'l' || str[i] == 't' || str[i] == 'a')
		i++;
	if (str[i] != '\0' && ft_file_exist(str, 0) == 0)
		ft_error(str[i]);
	if ((size_t)i != ft_strlen(str))
		return (0);
	return (1);
}

static void		ft_valid_or_not(char *cmp, s_struct **data)
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

void			ft_ls(char **params, int nb, int dir, int end)
{
	s_struct	*data;
	int			i;

	data = (s_struct *)malloc(sizeof(s_struct));
	i = 1;
	ft_initialise_struct(&data, nb, params);
	while (i != nb)
	{
		if (ft_is_option_valid(params[i]) == 1 && end == 0)
			ft_valid_or_not(params[i], &data);
		else if (ft_file_exist(params[i], 1) == 1)
		{
			end = 1;
			data->multifile[dir] = ft_strdup(params[i]);
			dir++;
		}
		else
			basic_error(params[i]);
		ft_strdel(&params[i]);
		i++;
	}
	ft_check_options(data);
}
