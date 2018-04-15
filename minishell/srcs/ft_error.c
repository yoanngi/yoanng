/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 10:04:43 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/15 10:35:22 by yoginet     ###    #+. /#+    ###.fr     */
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
**	Commande not found
*/

int			ft_error(int cmd, char **line)
{
	if (cmd == 0)
		return (0);
	else
	{
		ft_putstr_fd("minishell: command not found :", 2);
		ft_putstr_fd(*line, 2);
		ft_putstr_fd("\n", 2);
	}
	return (0);
}
