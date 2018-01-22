/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 11:18:17 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_simple(DIR *dir)
{
	if ((dir = opendir(".")) == NULL)
		exit(1);
	ft_putstr("c'est ouvert\n");
	while (readdir(dir) != NULL)
		ft_putstr("Fichier\n");
	if (closedir(dir) == -1)
		exit(1);
	ft_putstr("c'est fermer\n");
}

static void	ft_valid_or_not(char *cmp, s_struct *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
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
			data->invalid = &cmp[i];
		i++;
	}
}

static int	ft_analyse_params(s_struct *data, char **params, int nb)
{
	int		i;

	i = 0;
	while (i < nb - 1)
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

void	ft_ls(char **params, int nb)
{
	s_struct	*data;
	DIR			*dir;
	int			valid;

	dir = NULL;
	data = (s_struct *)malloc(sizeof(s_struct));
	valid = ft_analyse_params(data, params, nb);
	if (valid == 1 && data->tiret == 1)
	{
		ft_putstr("options\n");
	}
	else if (valid == 2)
		ft_error(data);
	else
		ft_ls_simple(dir);
}

