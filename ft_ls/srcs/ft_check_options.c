/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/02 14:31:07 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	ft_check_options :
**	Create chain list for all directory
**	Print path of the various directory
*/
static void		ft_target(s_struct *data)
{
	if (data->nb_file == 0 && data->invalid == 0)
	{
		data->nb_file = 1;
		data->multifile[0] = ft_strdup(".");
	}
}

static void		ft_display(s_struct *data, int index)
{
	if (data->lmin == 0)
		ft_print_ls(data, index);
	else
		ft_print_ls_liste(data);	
	if (data->nb_file > 1)
		ft_putchar('\n');
	data->liste = ft_clean_list(data->liste);
}

void	ft_check_options(s_struct *data)
{
	int i;
	int path;

	i = 0;
	path = data->nb_file;
	data->liste = NULL;
	ft_target(data);
	while (data->nb_file != 0)
	{
		data->liste = ft_ls_r(data, i);
		if (path > 1)
		{
			ft_putstr(data->multifile[i]);
			ft_putstr(":\n");
		}
		ft_display(data, i);
		free(data->multifile[i]);
		data->nb_file--;
		i++;
	}
}
