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
**	Check if line is valid
*/

static int		ft_line_is_valid(char *line)
{
	int		i;

	i = 0;
	if (ft_strcmp(line, "") == 0)
		return (0);
	while (line[i])
	{
		if (ft_isalnum(line[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

/*
**	Suite Minishell
**	Check exit, line and go check cmd
*/

static int		ft_minishell_suite(t_struct *data, char **line)
{
	clear_line(line);
	if ((ft_strcmp("exit", *line)) == 0 ||
	ft_strcmp("\"exit\"", *line) == 0 ||
	ft_strcmp("\'exit\'", *line) == 0)
		return (1);
	if (ft_line_is_valid(*line) == 1)
		ft_check_command(line, data, 0);
	return (0);
}

/*
**	Core Minishell
**	Check signal and read line
*/

int				ft_minishell(char **line, t_struct *data)
{
	int		q;

	q = 0;
	while (q == 0)
	{
		ft_display(data);
		signal(SIGINT, my_signal);
		get_next_line(0, line);
		if (*line != NULL)
			q = ft_minishell_suite(data, line);
		ft_strdel(line);
	}
	return (0);
}
