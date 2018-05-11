/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_signal.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/21 15:50:46 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 09:49:02 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Gestion du control C
*/

void		ft_control_c(int sig)
{
	if (sig & SIGINT)
	{
		ft_putstr("\n");
		ft_putstr("\033[32m");
		ft_putstr("$> ");
		ft_putstr("\033[0m");
	}
}
