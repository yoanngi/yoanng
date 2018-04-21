/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   good_func.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 11:20:03 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 13:31:21 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	start good function (for commande sup)
*/

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
	return (0);
}

/*
**	Check if other commande is good
*/

int				ft_cmd_annexe(char **line, t_struct *data)
{
	char	**tab;
	int		i;
	int		ret;

	tab = ft_strsplit(*line, ' ');
	i = 0;
	ret = 1;
	while (data->builtins[i])
	{
		if (ft_strcmp(tab[0], data->builtins[i]) == 0)
		{
			ft_search_func(line, data, i);
			ret = 0;
		}
		i++;
	}
	ft_del_tab(tab);
	return (ret);
}
