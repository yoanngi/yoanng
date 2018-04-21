/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_unsetenv.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:42 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 10:00:01 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Delete good line in env
*/

static int		ft_count(char **env, char *pattern)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], pattern, ft_strlen(pattern)) == 0)
			j++;
		i++;
	}
	return (j);
}

static char		**func_unsetenv_two(char *regex, t_struct *data)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	while (data->env[i])
		i++;
	if (!(tmp = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	i = 0;
	while (data->env[j])
	{
		if ((ft_strncmp(regex, data->env[j], ft_strlen(regex))) != 0)
		{
			tmp[i] = ft_strdup(data->env[j]);
			i++;
			j++;
		}
		else
			j++;
	}
	tmp[i] = NULL;
	return (tmp);
}

char			**func_unsetenv(char **line, t_struct *data)
{
	int		i;
	char	**tmp;
	char	*regex;

	i = 0;
	tmp = NULL;
	regex = ft_strsub(*line, 9, ft_strlen(*line) - 9);
	if (ft_count(data->env, regex) < 1)
	{
		ft_putstr_fd("unsetenv: Pattern not found: ", 2);
		ft_putstr_fd(regex, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (ft_count(data->env, regex) > 1)
	{
		ft_putstr_fd("unsetenv: Multiple pattern found: ", 2);
		ft_putstr_fd(regex, 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		tmp = func_unsetenv_two(regex, data);
		ft_del_tab(data->env);
		ft_strdel(&regex);
		return (tmp);
	}
	ft_strdel(&regex);
	return (data->env);
}
