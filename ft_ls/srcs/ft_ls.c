/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 16:42:09 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Initialise struct
*/

static t_struct		*ft_initialise_struct(int nb)
{
	t_struct	*data;

	data = (t_struct *)malloc(sizeof(t_struct));
	data->argc = nb;
	data->tiret = 0;
	data->rmaj = 0;
	data->rmin = 0;
	data->amin = 0;
	data->tmin = 0;
	data->lmin = 0;
	data->un = 0;
	data->omin = 0;
	data->invalid = 0;
	data->just_file = 0;
	data->nb_file = 0;
	data->multifile = NULL;
	data->filevalid = NULL;
	data->liste = NULL;
	return (data);
}

/*
**	Range tab in ascii order
*/

char				**ft_range_tab(char **tab, int len, int i)
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
			i = start;
		}
		else
			i++;
	}
	return (tab);
}

/*
**	Create structure for insert options
*/

void				ft_ls(char **params, int nb, int end)
{
	t_struct	*data;
	int			i;

	i = 1;
	data = ft_initialise_struct(nb);
	while (end == 0)
	{
		if (params[i][0] == '-' && ft_strlen(params[i]) > 1)
		{
			if (ft_option_exist(params[i], 1) == 1)
				ft_insert_valid_option(params[i], &data);
		}
		else
		{
			ft_range_tab(params, nb, i);
			data->multifile = ft_dir_valid(i, nb, params);
			data->filevalid = ft_file_valid(i, nb, params);
			ft_error_argv(i, nb, params, data);
			i = nb - 1;
		}
		i++;
		end = (i == nb) ? 1 : 0;
	}
	ft_check_options(data);
	data = ft_del_struct(data);
}
