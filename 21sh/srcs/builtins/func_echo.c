/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_echo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 12:18:01 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int				func_echo(t_struct *data, t_cmd *lst)
{
	/*
	char	*str;
	int		i;
	int		tiret_n;
	int		tiret_e;

	str = NULL;
	i = 0;
	if (ft_echo_path(*line, data) == 1)
		return (0);
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
	*/
	(void)data;
	(void)lst;
	return (0);
}
