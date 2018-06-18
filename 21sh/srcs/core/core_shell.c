/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 10:11:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/14 15:41:55 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

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
    t_ins   *cpy;

	ret = 0;
	data->commandes = ft_split_commandes(line);
    cpy = data->commandes;
    while (cpy)
    {
        ft_printf("cpy = %s\n", cpy->str);
	    ret = execute_commandes(cpy->cmd);
	    ft_printf("Valeur de data->ret_func = %d\n", data->ret_func);
	    if (ret == 1)
	    	ft_printf("On a une erreur\n");
    	if (ret == -1)
    		ft_printf("On doit quitter\n");
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
