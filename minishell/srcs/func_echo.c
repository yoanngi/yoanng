/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_echo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 09:51:02 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"
/*
static int		ft_check_split(char *str)
{
	int		i;
	int		nb;
	size_t	len;

	i = 0;
	nb = 0;
	len = ft_strlen(str);
	while (i < (int)len)
	{
		if (str[i] == '\\' && str[i + 1] == 'n')
		{
			nb++;
			i += 1;
		}
		if (str[i] == '\\' && str[i + 1] == 't')
		{
			nb++;
			i += 1;
		}
		i++;
	}
	if (nb != 0)
		return (nb);
	return (0);
}

static char		**ft_modif_tab(char **tab, int i, int nb)
{
	int		len;
	int		compt;
	int		ct;
	char	**new;

	len = ft_len_tab(tab);
	compt = 0;
	ct = 0
	new = (char **)malloc(sizeof(char *) * (len + nb + 1));
	while (compt != (len + nb))
	{
		if (compt < i)
		{
			new[compt] = ft_strdup(tab[ct]);
			ct++;
		}
		else
		{
			
		}
		compt++;
	}
	return (tab);
}
*/
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
	quit = 0;
//	while (tab[i])
//	{
//		if ((quit = ft_check_split(tab[i])) != 0)
//			tab = ft_modif_tab(tab, i, quit);
//		i++;
//	}
	char	**test;

	test = (char **)malloc(sizeof(char *) * 5);
	test[0] = ft_strdup("echo");
	test[1] = ft_strdup("bonjour\n");
	test[2] = ft_strdup("ca\n");
	test[3] = ft_strdup("va\n");
	test[4] = NULL;
	return (test);
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
