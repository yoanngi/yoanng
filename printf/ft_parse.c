/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 11:37:24 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 13:40:13 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_what_is_params(s_struct *data, int i)
{
	if (data->s[i] == '%' && data->s[i + 1] == 's')
		data->simple_s = 1;
	else if (data->s[i] == '%' && data->s[i + 1] == 'd')
		data->simple_d = 1;
	else if (data->s[i] == '%' && data->s[i + 1] == '+')
		data->flag_plus = 1;
	else if (data->s[i] == '%' && data->s[i + 1] == '-')
		data->flag_moins = 1;
	else if (data->s[i] == '%' && data->s[i + 1] == ' ')
		data->flag_space = 1;
	else if (data->s[i] == '%' && data->s[i + 1] == '#')
		data->flag_diese = 1;
	else if (data->s[i] == '%' && ft_isdigit(data->s[i + 1]) == 1)
		data->pre_befor = 1;
	else if (data->s[i] == '%' && data->s[i + 1] == '.')
		data->point = 1;
	else if (data->s[i] == '%' && data->s[i + 1] == '%')
		data->dmodulo = 1;
}

static int		ft_insert_valid(s_struct *data)
{
	int		i;
	int		j;
	char	*cpy;
	char	*tmp;

	i = 0;
	j = 0;
	cpy = ft_strdup(data->s);
	tmp = ft_strnew(ft_strlen(data->s));
	while (cpy[i])
	{
		if (cpy[i] == '%')
		{
			ft_what_is_params(data, i);
			j = 1;
		}
		else
			cpy[i] = tmp[i];
		if (j == 1)
		{
			i = ft_check_options(data, i);
			j = 0;
		}
		else
			i++;
	}
	return (0);
}

int				ft_parse(s_struct *data)
{
	ft_insert_valid(data);
	return (ft_strlen(data->s_final));
}
