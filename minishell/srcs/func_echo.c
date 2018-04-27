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
**	Print good line env
*/

static void		echo_env(char *str, t_struct *data)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strsub(str, 1, ft_strlen(str) - 1);
	while (data->env[i])
	{
		if (ft_strncmp(tmp, data->env[i], ft_strlen(tmp)) == 0)
			ft_putstr(data->env[i] + ft_strlen(str));
		i++;
	}
	ft_strdel(&tmp);
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

/*
**	Check special char && print line
*/

static void		echo_clear_string(char *str)
{
	int		i;
	int		ret;
	size_t	len;

	i = 0;
	ret = 0;
	if (ft_strstr(str, "\\r") != NULL || ft_strstr(str, "\\b") != NULL)
	{
		ft_putstr("char special r or b\n");
		return ;
	}
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
**	Print line and check \[...]
*/

static void		echo_clear_string_simple(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		if (str[i] == '\0')
			return ;
		else if (str[i] == '\\' && str[i + 1] != '\\')
		{
			i++;
			ft_putchar(str[i]);
		}
		else if (str[i] == '\\' && str[i + 1] == '\\')
		{
			ft_putstr("\t");
			i += 2;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

/*
**	Core echo
*/

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
	option_echo(j);
	ft_del_tab(tab);
	return (0);
}
