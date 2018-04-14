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

/*
**	Print infos in term
*/
static void		ft_display(void)
{
	ft_putstr("$> ");
	// Add print User
}

/*
**	Check commande and execute
*/
static int		ft_check_command(char **line, t_struct *data)
{
	int test;

	test = execve(data->path, line, NULL);
	printf("Valeur de execve = %d\n", test);
	ft_execute(line, data);
	return (0);
}

/*
**	Core Minishell
*/
int				main(int argc, char **argv, char **env)
{
	char		*line;
	t_struct	*data;

	(void)argc;
	(void)argv;
	line = NULL;
	data = ft_my_struct(env);
	while (1)
	{
		ft_display();
		get_next_line(0, &line);
		ft_check_command(&line, data);
		ft_strdel(&line);
	}
	ft_delete_struct(data);
	return (0);
}
