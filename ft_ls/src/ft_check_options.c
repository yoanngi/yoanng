/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 14:44:00 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
/*
static t_lst		ft_sort_liste(s_strcut *data)
{
	if (data->tmin == 1)
	{

	}
	if (data->rmin == 1)
	{

	}
	return ();
}
*/
void	ft_check_options(s_struct *data)
{
	data->liste = NULL;
	if (data->file == NULL)
		data->file = ft_strdup(".");
	if (data->rmaj == 1)
		data->liste = ft_ls_r(data);
	if (data->lmin == 1)
		data->liste = ft_ls_l(data);
//	data->liste = ft_sort_liste(data);
	printf("***********************AFFICHAGE******************************\n");
	ft_print_ls_liste(data);
}
