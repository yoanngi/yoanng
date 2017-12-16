/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tab_params.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 13:36:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 13:55:14 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

s_struct	*ft_tab_params(s_struct *ma_struct)
{
	int		nb_params;
	int		index;
	char	*cpy;

	nb_params = ma_struct->argc;
	index = 0;
	cpy = ft_strdup(ma_struct->s);
	while (cpy[index])
	{
		i = 0;
		while (c[i])
		{
			if (cpy[index] == '%' && cpy[index + 1] == c)
				ma_struct->argv = ft_strsub(cpy, index, 1);
			i++;
		}
		index++;
	}

	return (ma_struct);
}
