/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tab_params.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 13:36:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 15:28:19 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

s_struct		*ft_tab_params(s_struct *ma_struct, int i)
{
	int		index;
	int		compt;
	char	*cpy;

	index = 0;
	compt = 0;
	i = 0;
	cpy = ft_strdup(ma_struct->s);
	ft_malloc_tab(ma_struct->argv, ma_struct->argc + 1);
	while (cpy[index] || compt != ma_struct->argc)
	{
		if (cpy[index] == '%')
		{
			ma_struct->argv[compt] = ft_strsub(cpy, index, 3);
			compt++;
		}
		index++;
	}
	ft_strdel(&cpy);
	return (ma_struct);
}
