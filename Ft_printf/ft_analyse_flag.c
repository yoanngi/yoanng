/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_analyse_flag.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 12:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 14:51:13 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		where_is_it(char *str)
{
	int i;

	i = 0;
	while (str[i] != '%')
		i++;
	return (i);
}

int				ft_analyse_flag(s_struct *data, int i)
{
	char	*str;

	str = ft_strdup(data->s);
	i = where_is_it(str);
	if (str[i + 1] == '+')
		data->flag_plus = i;
	else if (str[i + 1] == '-')
		data->flag_moins = i;
	else if (str[i + 1] == '#')
		data->flag_diese = i;
	i++;
return (0);
}
