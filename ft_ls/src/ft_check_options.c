/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 14:07:57 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_check_options(s_struct *data)
{
	int i;
	int path;

	i = 0;
	path = data->nb_file;
	data->liste = NULL;
	while (data->nb_file != 0)
	{
		if (data->rmaj == 1)
			data->liste = ft_ls_r(data, i);
		if (data->lmin == 1)
			data->liste = ft_ls_l(data, i);
		if (path > 1)
		{
			ft_putstr(data->multifile[i]);
			ft_putstr(":\n");
		}
		ft_print_ls_liste(data, i);
		if (data->nb_file > 1)
			ft_putchar('\n');
		data->liste = ft_clean_list(data->liste);
		data->nb_file--;
		i++;
	}
}
