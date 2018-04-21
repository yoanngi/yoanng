/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 10:04:43 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 15:12:12 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Error std
*/

void		basic_error(char *name)
{
	ft_putstr_fd("Error :", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
}

/*
**	No such file of directory
*/

void		ft_error_dir(char *name, char *pre)
{
	ft_putstr_fd(pre, 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

/*
**	Commande not found
*/

int			ft_error(int cmd, char **line)
{
	if (cmd == 0)
		return (0);
	else
	{
		ft_putstr_fd(*line, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	return (0);
}

/*
**	Error unsetenv
*/

void		ft_error_unset(char *str, int what)
{
	if (what == 1)
	{
		ft_putstr_fd("unsetenv: Pattern not found: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (what == 2)
	{
		ft_putstr_fd("unsetenv: Multiple pattern found: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
	}
}
