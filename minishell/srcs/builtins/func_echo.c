/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_echo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 15:49:40 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	if option -n, print %
*/

static void		option_echo(int j)
{
	if (j == 0)
		ft_putchar('\n');
	else
		ft_putendl("\033[7m%\033[0m");
}


/*
**	Print good char special if is in the line
*/

static int		echo_clear_suite(char *str, int i)
{
	if (str[i] == '\\' && (str[i + 1] == 'n' || str[i + 1] == 't' ||
	str[i + 1] == 'a' || str[i + 1] == 'v' || str[i + 1] == 'f'))
	{
		if (str[i + 1] == 'n')
			ft_putstr("\n");
		else if (str[i + 1] == 't')
			ft_putstr("\t");
		else if (str[i + 1] == 'a')
			ft_putstr("\a");
		else if (str[i + 1] == 'v')
			ft_putstr("\v");
		else if (str[i + 1] == 'f')
			ft_putstr("\f");
		return (2);
	}
	return (0);
}

static void		echo_clear_string(char *str)
{
	int		i;
	int		ret;
	size_t	len;

	i = 0;
	ret = 0;
	echo_clear_special(&str);
	len = ft_strlen(str);
	while (i < (int)len)
	{
		if (str[i] == '\"')
			i++;
		else
		{
			ret = echo_clear_suite(str, i);
			if (ret == 0)
			{
				ft_putchar(str[i]);
				i++;
			}
			else
				i += ret;
		}
	}
}

/*
**	Core echo
*/

static void		func_echo_suite(char **tab, int i, t_struct *data)
{
	while (tab[i])
	{
		if (ft_strstr(tab[i], "$") != NULL)
			echo_env(tab[i], data);
		else if (ft_strstr(tab[i], "\"") != NULL || ft_strstr(tab[i], "\'") != NULL)
			echo_clear_string(tab[i]);
		else
			echo_clear_string_simple(tab[i]);
		i++;
	}
}

int				func_echo(char **line, t_struct *data)
{
	char	**tab;
	int		i;
	int		j;

	j = 0;
	tab = ft_strsplit(*line, ' ');
	if (ft_len_tab(tab) >= 1)
	{
		if (ft_strcmp(tab[1], "-n") == 0)
			j = 1;
	}
	i = 1;
	if (j == 1)
		i = 2;
	func_echo_suite(tab, i, data);
	option_echo(j);
	ft_del_tab(tab);
	return (0);
}
