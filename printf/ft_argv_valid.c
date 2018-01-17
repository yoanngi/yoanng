/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_argv_valid.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 10:31:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 11:36:28 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_argv_valid(char *str, int index)
{
	int		pvalid;
	char	*c;

	pvalid = 0;
	c = "sSpdDioOuUxXcChljz#0-+";
	while (pvalid != 22)
	{
		if (str[index] == '%' && str[index + 1] == c[pvalid])
			return (1);
		pvalid++;
	}
	return (0);
}
