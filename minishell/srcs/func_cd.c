/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_cd.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:21:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/15 15:27:35 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static char		*func_return_target(char *line, char *home)
{
	char	*target;
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
		i++;
	if (i == 1)
		target = ft_strdup(home);
	else
		target = ft_strdup(tab[i - 1]);
	ft_del_tab(tab);
	return (target);
}

int		func_cd(char **line, t_struct *data)
{
	int		i;
	int		ret;
	char	*tmp;

	i = 0;
	tmp = func_return_target(*line, data->home);
	if ((ret = chdir(tmp)) == -1)
	{
		ft_putstr_fd("cd: no such file of directory: ", 2);
		ft_putstr_fd(tmp, 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_strdel(&data->current_path);
		data->current_path = ft_strdup(tmp);
	}
	ft_strdel(&tmp);
	return (1);
}
