/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 14:52:47 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_valid_or_not(char *cmp, s_struct *data)
{
	int i;

	i = 0;
	while (cmp[i])
	{
		if (cmp[i] == '-')
			data->tiret = 1;
		else if (cmp[i] == 'R')
			data->rmaj = 1;
		else if (cmp[i] == 'r')
			data->rmin = 1;
		else if (cmp[i] == 'a')
			data->amin = 1;
		else if (cmp[i] == 't')
			data->tmin = 1;
		else if (cmp[i] == 'l')
			data->lmin = 1;
		else
			data->invalid = ft_strdup(cmp);
		i++;
	}
}

static int		ft_analyse_params(s_struct *data, char **params, int nb)
{
	int		i;

	i = 1;
	while (i != nb)
	{
		ft_valid_or_not(params[i], data);
		i++;
	}
	if (data->invalid != NULL)
		return (2);
	if (data->tiret == 1 || data->rmaj == 1 || data->rmin == 1 ||
	data->amin == 1 || data->tmin == 1 || data->lmin == 1)
		return (1);
	return (0);
}

static int		ft_file_exist(char *file_ornot)
{
	DIR		*dir;

	if ((dir = opendir(file_ornot)) == NULL)
		return (0);
	closedir(dir);
	return (1);
}

void			ft_ls(char **params, int nb)
{
	s_struct	*data;
	DIR			*dir;
	char		*cpy;

	dir = NULL;
	data = (s_struct *)malloc(sizeof(s_struct));
	data->invalid = NULL;
	data->argc = nb;
	cpy = ft_strdup(params[nb - 1]);
	if (ft_file_exist(cpy) == 1)
	{
		data->file = ft_strdup(params[nb - 1]);
		nb -= 1;
	}
	ft_strdel(&cpy);
	if (data->argc == 2 && data->file != NULL)
		ft_ls_simple(data->file);
	else
	{
		if (ft_analyse_params(data, params, nb) == 1)
			ft_check_options(data, dir);
		else if (ft_analyse_params(data, params, nb) == 2)
			ft_error(data);
	}
}
