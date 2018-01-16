/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_analyse_flag.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 12:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:43:16 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_precision(s_struct *data, char c, int i)
{
	if (ft_isdigit(c) == 1)
		data->prebefor = i;
	else if (c == '.')
		data->point = i;
}

static void		ft_flag(s_struct *data, char c, int i)
{
	if (c == '+')
		data->flag_plus = i;
	else if (c == '-')
		data->flag_moins = i;
	else if (c == '#')
		data->flag_diese = i;
	else if (c == ' ')
		data->flag_space = i;
}

int				ft_analyse_flag(s_struct *data, int i)
{
	char	*str;

	str = ft_strdup(data->s);
	while (str[i])
	{
		if (str[i] == '%')
			ft_precision(data, str[i + 1], i);
			ft_flag(data, str[i + 1], i);
		i++;
	}
	return (0);
}
