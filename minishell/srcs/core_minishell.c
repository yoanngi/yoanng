/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_minishell.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 13:35:53 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Core Minishell
**	Check signal, Check empty line
**	if cmd_special == 1 => ft_enclosing.c (change prompt) => minishell_suite
**
**	ft_enclosing a revoir
*/

static int		ft_minishell_suite(t_struct *data, char **line, int cmd)
{
	if ((ft_strcmp("exit", *line)) == 0 || ft_strcmp("\"exit\"", *line) == 0)
		return (1);
	if ((ft_strcmp("", *line)) != 0)
	{
		if (cmd_special(*line, data, 0) == 0)
		{
			cmd = ft_check_command(line, data, 0);
			ft_error(cmd, line);
		}
		else
			ft_minishell_spe(data, line);
	}
	return (0);
}

int				ft_minishell(char **line, t_struct *data)
{
	int		q;
	int		cmd;

	q = 0;
	cmd = 0;
	while (q == 0)
	{
		ft_display(data);
		signal(SIGINT, my_signal);
		get_next_line(0, line);
		if (*line != NULL)
			q = ft_minishell_suite(data, line, cmd);
		ft_strdel(line);
	}
	return (0);
}
