/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_valid_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 10:29:38 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:46:53 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_option_exist(char *str, int nb)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == ' ' || str[i] == 'R' || str[i] == 'r' ||
			str[i] == 'l' || str[i] == 't' || str[i] == 'a')
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

void		ft_insert_valid_option(char *cmp, s_struct **data)
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
		i++;
	}
}

int			ft_count_files_valid(int argc, char **argv)
{
	char	*cpy;
	int		i;
	int		nb;
	int		tmp;

	i = 0;
	nb = 0;
	tmp = argc;
	while (i != (argc - 1))
	{
		cpy = ft_strdup(argv[tmp - 1]);
		if (ft_access_or_not(&cpy) == 1)
			nb += 1;
		ft_strdel(&cpy);
		i++;
		tmp--;
	}
	return (nb);
}
