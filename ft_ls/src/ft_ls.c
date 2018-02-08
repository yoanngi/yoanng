/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 16:37:36 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

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
		else
			(*data)->invalid = ft_strdup(cmp);
		i++;
	}
}

static int		ft_analyse_params(s_struct **data, char **params, int nb)
{
	int		i;

	i = 1;
	while (i != nb)
	{
		ft_valid_or_not(params[i], data);
		i++;
	}
	if ((*data)->invalid != NULL)
		return (2);
	if ((*data)->tiret == 1 || (*data)->rmaj == 1 || (*data)->rmin == 1 ||
	(*data)->amin == 1 || (*data)->tmin == 1 || (*data)->lmin == 1)
		return (1);
	return (0);
}

static int		ft_files_valid(int argc, char **argv)
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
		if (ft_file_exist(cpy) == 1)
			nb += 1;
		ft_strdel(&cpy);
		i++;
		tmp--;
	}
	return (nb);
}

void			ft_ls(char **params, int nb)
{
	s_struct	*data;
	char		*arg;

	data = (s_struct *)malloc(sizeof(s_struct));
	data->invalid = NULL;
	data->argc = nb;
	data->nb_file = ft_files_valid(nb, params);

	if (data->nb_file == 1)
		data->file = ft_one_argv(nb, params);
	if (data->nb_file > 1)
		data->multifile = ft_multi_argv(nb, params, data->nb_file);
	if (data->nb_file == 0)
		data->file = ft_strdup(".");
	if ((nb - 1) != data->nb_file)
	{
		arg = ft_add_option(nb, params, data->nb_file);
		ft_analyse_params(&data, arg, ((nb - 1) - data->nb_file));
		ft_check_options(data);
	}
	else
		ft_ls_simple(data->file);
}
