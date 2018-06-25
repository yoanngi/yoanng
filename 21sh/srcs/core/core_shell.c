/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 10:11:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 11:42:48 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	parse_line : Parse la line et la convertit en liste chainer
**	Valeur de retour de ret :
**	0 -> ok
**	1 -> erreur de pipe ou fork
**	-1 -> On a un exit
*/

static int		parse_line(t_struct *data, char **line)
{
	int		ret;
	t_ins	*cpy;

	ret = 0;
	data->commandes = ft_split_commandes(line, data);
	cpy = data->commandes;
	while (cpy)
	{
		ft_printf("******* Commande executer : |%s|\n", cpy->str);
		ret = execute_commandes(cpy->cmd);
		ft_printf("******* Valeur de retour = %d\n", ret);
		cpy = cpy->next;
	}
	data->commandes = clear_ins(data->commandes);
	return (0);
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
