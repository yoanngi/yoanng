/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_echo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/15 13:51:31 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Split a modifier, probleme des retours a la lignes
*/

static char		**func_split_echo(char *line)
{
	char	**tab;
	char	*tmp;

	tmp = ft_strsub(line, 4, ft_strlen(line) - 4);
	tab = ft_strsplit(tmp, '"');
	ft_strdel(&tmp);
	return (tab);
}

int				func_echo(char **line, t_struct *data)
{
	int		i;
	char	**tab;
	char	*echo;

	i = 0;
	tab = func_split_echo(*line);
	while (data->tab_path[i])
	{
		echo = ft_add_line(data->tab_path[i], "echo");
		if ((ft_process(echo, tab)) > -1)
		{
			ft_strdel(&echo);
			ft_del_tab(tab);
			return (0);
		}
		ft_strdel(&echo);
		i++;
	}
	ft_del_tab(tab);
	ft_error(1, line);
	return (1);
}
