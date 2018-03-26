/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_valid_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 10:29:38 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 16:49:50 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Verify if options is valid
*/

int			ft_option_exist(char *str, int nb)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == ' ' || str[i] == 'R' || str[i] == 'r' ||
			str[i] == 'l' || str[i] == 't' || str[i] == 'a' || str[i] == '1' ||
		str[i] == 'o')
		i++;
	if (nb == 1 && (size_t)i != ft_strlen(str))
	{
		ft_error(str[i]);
		return (0);
	}
	if ((size_t)i != ft_strlen(str))
		return (0);
	return (1);
}

/*
**	Insert options in struct
*/

void		ft_insert_valid_option(char *cmp, t_struct **data)
{
	int i;

	i = 0;
	while (cmp[i])
	{
		if (cmp[i] == '-')
			(*data)->tiret = 1;
		else if (cmp[i] == 'R')
			(*data)->rmaj = 1;
		else if (cmp[i] == 'r')
			(*data)->rmin = 1;
		else if (cmp[i] == 'a')
			(*data)->amin = 1;
		else if (cmp[i] == 't')
			(*data)->tmin = 1;
		else if (cmp[i] == 'l')
			(*data)->lmin = 1;
		else if (cmp[i] == '1')
			(*data)->un = 1;
		else if (cmp[i] == 'o')
			(*data)->omin = 1;
		i++;
	}
	if ((*data)->lmin == 0 && (*data)->omin == 1)
		(*data)->lmin = 1;
}
