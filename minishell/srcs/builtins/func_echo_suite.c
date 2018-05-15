/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_echo_suite.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 11:06:06 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	if option -n > print %\n
*/

void		option_echo(int j, t_struct *data)
{
	if (j == 0)
		ft_putchar('\n');
	else
	{
		if (data->option_echo == 0)
			ft_putendl("\033[7m%\033[0m");
	}
}

/*
**	Check options -n/-e/-ne/-en in line
*/

int			ft_check_option(char *line, int n_or_e)
{
	char	**tab;
	int		ret;

	ret = 0;
	tab = ft_strsplit(line, ' ');
	if (ft_len_tab(tab) >= 2)
	{
		if (ft_strcmp(tab[1], "-n") == 0 && n_or_e == 0)
			ret = 1;
		else if (ft_strcmp(tab[1], "-ne") == 0 && n_or_e == 0)
			ret = 2;
		else if (ft_strcmp(tab[1], "-en") == 0 && n_or_e == 0)
			ret = 2;
		else if (ft_strcmp(tab[1], "-e") == 0 && n_or_e == 1)
			ret = 1;
	}
	ft_del_tab(tab);
	return (ret);
}

/*
**	print good line in env if exist
*/

static int	ft_search_env_suite(char *str, int i)
{
	int quit;

	quit = 0;
	while (quit == 0)
	{
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\f' || str[i] == '\v' || str[i] == '\0')
			quit = 1;
		else
			i++;
	}
	return (i);
}

int			ft_search_env(char *str, int i, t_struct *data, int i2)
{
	char	*search;

	search = NULL;
	i2 = i;
	i = ft_search_env_suite(str, i);
	search = ft_strsub(str, i2 + 1, (i - i2 - 1));
	i2 = 0;
	if (data->env != NULL)
	{
		while (data->env[i2])
		{
			if (ft_strncmp(data->env[i2], search, ft_strlen(search)) == 0)
			{
				ft_putstr(data->env[i2] + (ft_strlen(search) + 1));
				i2 = ft_strlen(search);
				ft_strdel(&search);
				data->option_echo = 0;
				return (i2 + 1);
			}
			i2++;
		}
	}
	i2 = ft_strlen(search);
	ft_strdel(&search);
	data->option_echo = 1;
	return (i2 + 1);
}
