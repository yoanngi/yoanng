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

static void		print_ascii_art(void)
{
	ft_printf("       ::::::::    :::   ::::::::  :::    ::: \n");
	ft_printf("     :+:    :+: :+:+:  :+:    :+: :+:    :+:  \n");
	ft_printf("          +:+    +:+  +:+        +:+    +:+   \n");
	ft_printf("       +#+      +#+  +#++:++#++ +#++:++#++    \n");
	ft_printf("    +#+        +#+         +#+ +#+    +#+     \n");
	ft_printf("  #+#         #+#  #+#    #+# #+#    #+#      \n");
	ft_printf("########## ####### ########  ###    ###       \n");
	ft_printf("\n");
	ft_printf("© - volivry\n");
	ft_printf("© - yoginet\n");
}

int				main(int argc, char **argv, char **env)
{
	t_struct	*data;
	int			code_exit;

	(void)argc;
	(void)argv;
	print_ascii_art();
	code_exit = 0;
	data = NULL;
	data = init_struct(env);
	core_shell(data);
	code_exit = ft_delete_struct(&data);
	printf("CODE EXIT = %d\n", code_exit);
	return (code_exit);
}
