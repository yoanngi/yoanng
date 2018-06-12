/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 10:11:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/12 18:14:19 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int		parse_line(t_struct *data, char **line)
{
	int		ret;

	ret = 0;
	data->commandes = ft_split_commandes(line, &data);
	ret = execute_commandes(data);
	printf("%s -> retour = %d\n", __func__, ret);
	printf("%s -> data->ret_func = %d\n", __func__, data->ret_func);
	data->commandes = clear_commandes(data->commandes);
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
