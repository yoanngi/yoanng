/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 10:11:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/11 11:12:24 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int		parse_line(t_struct *data, char **line)
{
	int		ret;

	ret = 0;
	// retourne une liste chainer des commandes separer et clean
	data->commandes = ft_split_commandes(line, &data);
	printf("PARSING OK\n");

	// Execution des commmandes.
	ret = execute_commandes(data);
	printf("EXECUTION OK\n");

	// del liste chainer
	data->commandes = clear_commandes(data->commandes);
	printf("CLEAR COMMANDE OK\n");
	return (ret);
}

void			core_shell(char **line, t_struct *data)
{
	int		quit;

	quit = 0;
	while (quit == 0)
	{
		ft_display(data);
//		signal(SIGINT, my_signal);
		get_next_line(0, line);
		if (*line != NULL)
			quit = parse_line(data, line);
		ft_strdel(line);
	}
}
