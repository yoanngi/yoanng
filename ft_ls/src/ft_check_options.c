/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 16:36:28 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_check_options(s_struct *data)
{
	if (data->file == NULL)
		data->file = ft_strdup(".");
	if (data->rmaj == 1)
		data->liste = ft_ls_r(data);
	if (data->lmin == 1)
		data->liste = ft_ls_l(data);

/*	if (data->tmin == 1)// -t
		ft_sort(data);
	if (data->amin == 1)// -a
		ft_filecacher(data);
*/
		ft_print_ls_liste(data);
}
