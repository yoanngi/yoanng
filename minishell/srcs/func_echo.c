/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_echo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 15:05:44 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Part 2 : Split line for commande echo	
*/
/*
static char		**func_split_echo_suite(char **tab)
{
	char	**new_tab;
	int		len;
	int		i;

	new_tab = NULL;
	len = ft_len_tab(tab);
	i = 1;
	while (i != len)
	{
		new_tab = ft_strsplit(tab[i], ' ');
			
	}
	
	
	return (new_tab);
}
*/
/*
**	Part 1 : Split line for commande echo	
**	34 = "
**	92 = \
*/

static char		**func_split_echo(char *line)
{
	char	**tab;
	int		i;
	int		quit;

	i = 0;
	quit = 0;
	while (quit == 0 && ((size_t)i < ft_strlen(line)))
	{
		if (line[i] == 34 && line[i - 1] != 92)
			quit = 1;
		i++;
	}
	tab = ft_strsplit(line, ' ');
//	if (quit == 1)
//		tab = func_split_echo_suite(char **tab);
	return (tab);
}

/*
**	Core echo
*/

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
