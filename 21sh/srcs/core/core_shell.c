/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 10:11:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/26 16:10:45 by yoginet     ###    #+. /#+    ###.fr     */
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
		if (cpy->cmd != NULL)
			ret = execute_commandes(data, cpy->cmd);
		if (ret == -1)
		{
			ft_putstr_fd("--> exit shell <--\n", 2);
			data->commandes = clear_ins(data->commandes);
			return (1);
		}
		// A DETETE **********************************************************
		ft_printf("******* Commande executer : |%s|\n", cpy->str);
		ft_printf("******* Valeur de retour = %d\n", ret);
		cpy = cpy->next;
	}
	data->commandes = clear_ins(data->commandes);
	return (0);
}

/*
**	Boucle infini, Attend un retour different de zero pour exit
*/

void			my_signal(int sig)
{
	if (sig & SIGINT)
	{
		ft_putstr("\n");
		ft_putstr("\033[32m");
		ft_putstr("$> ");
		ft_putstr("\033[0m");
	}
}

void			core_shell(t_struct *data)
{
	int				quit;
	char			*line;

	quit = 0;
	line = NULL;
	while (quit == 0)
	{
		ft_display(data);
		if (signal(SIGINT, my_signal) == SIG_IGN)
			data->code_erreur = 130;
		get_next_line(0, &line);
		if (line != NULL)
			quit = parse_line(data, &line);
		ft_strdel(&line);
	}
}
