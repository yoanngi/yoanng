/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_echo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 15:54:38 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_check_split(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\' && str[i + 1] == 'n')
			return (1);
		i++;
	}
	return (0);
}

static char		**ft_modif_tab(char **tab, int i)
{
	i = 1;
	(void)tab;
	return (NULL);
}

/*
**	Part 2 : Split line for commande echo
**	34 = "
**	92 = \
*/

static char		**func_split_echo_suite(char **tab, int i, int j1, int j2)
{
	char	*tmp;

	while (tab[i])
	{
		j1 = 0;
		j2 = 0;
		tmp = ft_strnew(ft_strlen(tab[i]));
		while (tab[i][j1])
		{
			if (tab[i][j1] == 34 && tab[i][j1 - 1] != 92)
				j1++;
			else
			{
				tmp[j2] = tab[i][j1];
				j1++;
				j2++;
			}
		}
		tmp[j2] = '\0';
		ft_strdel(&tab[i]);
		tab[i] = ft_strdup(tmp);
		ft_strdel(&tmp);
		i++;
	}
	return (tab);
}

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
	if (quit == 1)
		tab = func_split_echo_suite(tab, 1, 0, 0);
	i = 1;
	while (tab[i])
	{
		if (ft_check_split(tab[i]) == 1)
			tab = ft_modif_tab(tab, i);
		i++;
	}
	return (tab);
}

/*
**	Core echo
**	!!!!!!!!!!! dquote a gerer ?
*/

int				func_echo(char **line, t_struct *data)
{
	int		i;
	char	**tab;
	char	*echo;

	i = 0;
	tab = func_split_echo(*line);
	// debug
	ft_putstr("DEBUG\n");
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
	i = 0;
	ft_putstr("END DEBUG\n");
	// end debug
	while (data->tab_path[i])
	{
		echo = ft_add_line(data->tab_path[i], "echo");
		if ((ft_process(echo, tab)) > -1)
		{
			ft_strdel(&echo);
			if (ft_strlen(*line) > 7)
			{
				if (ft_strcmp(tab[1], "-n") == 0)
					ft_putstr("\033[7m%\033[0m\n");
			}
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
