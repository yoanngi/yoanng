/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 14:27:21 by yoginet     ###    #+. /#+    ###.fr     */
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
	if (env[0] == NULL)
		data = ft_my_struct_null();
	else
		data = ft_my_struct(env);
	ft_minishell(&line, data, 0, 0);
	ft_strdel(&line);
	ft_delete_struct(data);
	return (0);
}
