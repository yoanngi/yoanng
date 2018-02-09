/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 15:09:24 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_check_options(s_struct *data)
{
	int i;

	i = 0;
	data->liste = NULL;
	printf("DEBUG :\n");
	printf("data->rmaj = %d\n", data->rmaj);
	printf("data->lmin = %d\n", data->lmin);
	while (data->nb_file != 0)
	{
		if (data->rmaj == 1)
			data->liste = ft_ls_r(data, i);
		if (data->lmin == 1)
			data->liste = ft_ls_l(data, i);
		ft_print_ls_liste(data);
		data->nb_file--;
	}
}
