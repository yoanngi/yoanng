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

/*
**	Func echo provisoire
** 	reste option a gerer
*/

int				func_echo(t_struct *data, t_cmd *lst)
{
	int		i;
	int		noreturn;

	i = 1;
	noreturn = 0;
	(void)data;
	while (lst->tab_cmd[i])
	{
		if (lst->tab_cmd[i] != NULL && i == 1)
		{
			if (ft_strcmp(lst->tab_cmd[i], "-n") == 0)
				noreturn = 1;
			else
				ft_putstr(lst->tab_cmd[i]);
		}
		else
			ft_putstr(lst->tab_cmd[i]);
		if (lst->tab_cmd[i + 1] != NULL)
			ft_putstr(" ");
		i++;
	}
	if (noreturn == 0)
		ft_putstr("\n");
	else
		ft_putstr("\033[7m%\033[0m\n");
	return (0);
}
