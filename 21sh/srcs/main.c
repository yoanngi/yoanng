/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 12:08:41 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Main 42sh
**	Ignore argc et argv
**	Retourne la valeur de exit
*/

static int      ft_test_system(void)
{
    int     i;
    char    *test;

    i = 0;
    test = NULL;
    while (i < 10)
    {
        if (!(test = ft_strnew(2000000)))
            return (EXIT_FAILURE);
        ft_strdel(&test);
        i++;
    }
    return (EXIT_SUCCESS);
}

static void		print_ascii_art(void)
{
	ft_putstr(MAGENTA);
	ft_printf("       ::::::::    :::   ::::::::  :::    ::: \n");
	ft_putstr(CYAN);
	ft_printf("     :+:    :+: :+:+:  :+:    :+: :+:    :+:  \n");
	ft_putstr(BLUE);
	ft_printf("          +:+    +:+  +:+        +:+    +:+   \n");
	ft_putstr(GREEN);
	ft_printf("       +#+      +#+  +#++:++#++ +#++:++#++    \n");
	ft_putstr(YELLOW);
	ft_printf("    +#+        +#+         +#+ +#+    +#+     \n");
	ft_putstr(WHITE);
	ft_printf("  #+#         #+#  #+#    #+# #+#    #+#      \n");
	ft_putstr(MAGENTA);
	ft_printf("########## ####### ########  ###    ###       \n");
	ft_putstr(RESET);
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
    if (ft_test_system() == 1)
        return (1);
	print_ascii_art();
	code_exit = 0;
	data = NULL;
	data = init_struct(env);
	core_shell(data);
	printf("DELETE STRUCTURE\n");
	code_exit = ft_delete_struct(&data);
	printf("DELETE OK\n");
	return (code_exit);
}
