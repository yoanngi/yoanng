/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 15:18:15 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_check_exit(char **line, char **env)
{
	int i;

	i = 0;
	if (ft_strcmp(*line, "exit\n") == 0)
		i = 1;
	if (i == 0)
		ft_execute(line, env);
	ft_bzero(*line, 255);
	if (i == 0)
		ft_putstr(">$ ");
	return (i);
}

int				main(int argc, char **argv, char **env)
{
	char	*line;
	int		exit;

	(void)argc;
	(void)argv;
	exit = 0;
	line = ft_strnew(255);
	ft_putstr(">$ ");
	while (exit == 0)
	{
		read(0, line, 255);
		exit = ft_check_exit(&line, env);
	}
	ft_strdel(&line);
	return (0);
}
