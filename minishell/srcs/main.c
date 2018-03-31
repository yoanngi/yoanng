/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 15:02:19 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_print(char **line)
{
	int i;

	i = 0;
	printf("line = %s", *line);
	if (ft_strcmp(*line, "exit\n") == 0)
		i = 1;
	ft_bzero(*line, 255);
	if (i == 0)
		ft_putstr(">$ ");
	return (i);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		exit;

	(void)argc;
	(void)argv;
	exit = 0;
	line = ft_strnew(255);
	ft_putstr(">$ ");
	while (read(0, line, 255) && exit == 0)
	{
		exit = ft_print(&line);
	}
	return (0);
}
