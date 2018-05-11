/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_echo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 14:02:31 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Print special char
*/

int				ft_print_special(char *str, int i, int len)
{
	if (i >= len)
		return (0);
	if (str[i] == '\\' && (str[i + 1] == 'n' || str[i + 1] == 't' ||
				str[i + 1] == 'a' || str[i + 1] == 'v' || str[i + 1] == 'f'))
	{
		if (str[i + 1] == 'n')
			ft_putstr("\n");
		else if (str[i + 1] == 't')
			ft_putstr("\t");
		else if (str[i + 1] == 'a')
			ft_putstr("\a");
		else if (str[i + 1] == 'v')
			ft_putstr("\v");
		else if (str[i + 1] == 'f')
			ft_putstr("\f");
		return (2);
	}
	return (0);
}

/*
**	Core echo
*/

int				func_echo(char **line, t_struct *data)
{
	char	*str;
	int		i;
	int		tiret_n;
	int		tiret_e;

	str = NULL;
	i = 0;
	data->option_echo = 0;
	tiret_n = ft_check_option(*line, 0);
	tiret_e = ft_check_option(*line, 1);
	if (tiret_n == 0 && tiret_e == 0)
		str = ft_strsub(*line, 5, ft_strlen(*line) - 5);
	else
	{
		if (tiret_n == 1 || tiret_e == 1)
			str = ft_strsub(*line, 8, ft_strlen(*line) - 8);
		else if (tiret_n == 2)
			str = ft_strsub(*line, 9, ft_strlen(*line) - 9);
	}
	if (str)
		ft_print_echo(str, data, 0);
	option_echo(tiret_n, data);
	ft_strdel(&str);
	return (0);
}