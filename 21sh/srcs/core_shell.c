/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 10:11:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 12:09:44 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int		parse_line(t_struct *data, char **line)
{
	int		ret;

	ret = 0;
	// retourne une liste chainer des commandes separer et clean
	data->commande = ft_split_commande(line);

	// Execution des commmandes.
	ret = execute_commande(data, line);

	// del liste chainer
	clear_commande(data->commande);
	return (ret);
}

void			core_shell(char **line, t_struct *data)
{
	int		quit;

	quit = 0;
	while (quit == 0)
	{
		ft_display(data);
		signal(SIGINT, my_signal);
		get_next_line(0, line);
		if (*line != NULL)
			quit = parse_line(data, line);
		ft_strdel(line);
	}
	return (0);
}
