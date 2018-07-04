/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 12:33:12 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Main 42sh
**	Ignore argc et argv
**	Retourne la valeur de exit
*/

int				main(int argc, char **argv, char **env)
{
	t_struct	*data;
	int			code_exit;

	(void)argc;
	(void)argv;
	code_exit = 0;
	data = NULL;
	data = init_struct(env);
	core_shell(data);
	code_exit = ft_delete_struct(&data);
	if (data != NULL)
		ft_printf("LEAKS !!!!!!!\n");
	return (code_exit);
}
