/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_exit.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 15:37:47 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Free line and struct, exit programme
*/

void	func_exit(char **line, t_struct *data)
{
	ft_strdel(line);
	ft_delete_struct(data);
	// A delete
	ft_putstr_fd("Mode sleep(150)\n", 2);
	sleep(150);
	// end
	exit(EXIT_SUCCESS);
}
