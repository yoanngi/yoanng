/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cmd_annexe.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 11:20:03 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 13:54:55 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static char		**ft_initialise_builtins(void)
{
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char *) * 7)))
		return (NULL);
	tab[0] = ft_strdup("cd");
	tab[1] = ft_strdup("echo");
	tab[2] = ft_strdup("setenv");
	tab[3] = ft_strdup("unsetenv");
	tab[4] = ft_strdup("env");
	tab[5] = ft_strdup("exit");
	tab[6] = NULL;
	return (tab);
}

static int		ft_search_func(char **line, t_struct *data, int i)
{
	if (i == 0)
		func_cd(line, data);
	else if (i == 1)
		func_echo(line, data);
	else if (i == 2)
		data->env = func_setenv(line, data);
	else if (i == 3)
		data->env = func_unsetenv(line, data);
	else if (i == 4)
		func_env(line, data);
	else if (i == 5)
		func_exit(line, data);
	return (0);
}

int				ft_cmd_annexe(char **line, t_struct *data)
{
	char	**tab;
	char	**builtins;
	int		i;
	int		ret;

	tab = ft_strsplit(*line, ' ');
	builtins = ft_initialise_builtins();
	i = 0;
	ret = 1;
	while (builtins[i])
	{
		if (ft_strcmp(tab[0], builtins[i]) == 0)
		{
			ft_search_func(line, data, i);
			ret = 0;
		}
		i++;
	}
	ft_del_tab(tab);
	ft_del_tab(builtins);
	return (ret);
}
