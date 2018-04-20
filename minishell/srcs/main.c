/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 10:54:53 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int				main(int argc, char **argv, char **env)
{
	char		*line;
	t_struct	*data;

	(void)argc;
	(void)argv;
	line = NULL;
	data = ft_my_struct(env);
	ft_minishell(&line, data);
	ft_strdel(&line);
	ft_delete_struct(data);
	return (0);
}
