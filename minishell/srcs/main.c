/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 15:32:31 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_check_exit(char **line, t_struct *data)
{
	int i;

	i = 0;
	if (*line == NULL)
		return (i);
	if (ft_strcmp(*line, "exit\n") == 0)
		i = 1;
	if (i == 0)
		ft_execute(line, data);
	ft_bzero(*line, 255);
	if (i == 0)
		ft_putstr(">$ ");
	return (i);
}

int				main(int argc, char **argv, char **env)
{
	char		*line;
	int			exit;
	t_struct	*data;

	(void)argc;
	(void)argv;
	exit = 0;
	line = ft_strnew(255);
	data = ft_my_struct(env);
	ft_putstr(">$ ");
	while (exit == 0)
	{
		read(0, line, 255);
		exit = ft_check_exit(&line, data);
	}
	ft_strdel(&line);
	ft_delete_struct(data);
	return (0);
}
