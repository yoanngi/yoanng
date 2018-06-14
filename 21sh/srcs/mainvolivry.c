/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 19:45:45 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

static void	line_edit(void)
{
	int	loop;
	char	*line;
	static int	curs_idx = 0;

	line = NULL;
	loop = 1;
	(void)line;
	raw_term_mode();
	while (loop)
		line = get_key(&loop, line, &curs_idx);
	get_line(1, &line);
	default_term_mode();
}

int				main(int argc, char **argv, char **env)
{
//	t_struct	*data;

	(void)argc;
	(void)argv;
	(void)env;
//	get_line(0, &line);
	while (1)
		line_edit();
	/*
	data = init_struct(env);
	core_shell(&line, data);
	ft_strdel(&line);
	ft_delete_struct(data);*/
	return (0);
}
