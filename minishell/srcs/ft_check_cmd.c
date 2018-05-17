/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_cmd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 12:27:19 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 15:35:12 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_existe_in_path(t_struct *data, char **path)
{
	char	*pat;
	int		i;

	pat = ft_return_path(*path);
	i = 0;
	while (data->tab_path[i])
	{
		if (ft_strcmp(data->tab_path[i], pat) == 0)
		{
			ft_strdel(&pat);
			return (1);
		}
		i++;
	}
	ft_strdel(&pat);
	return (0);
}

/*
**  If path is good > ft_process (fork && execve)
*/

static int		ft_exec_cmd_path(t_struct *data, char **tab, char **tmp)
{
	int		i;
	int		exec;

	i = 0;
	exec = -1;
	while (data->tab_path[i])
	{
		*tmp = ft_add_line(data->tab_path[i], &tab[0], data);
		if (good_path(*tmp, tab[0]) == 1)
		{
			if ((exec = ft_process(*tmp, tab, data->env)) > -1)
				return (0);
		}
		ft_strdel(tmp);
		i++;
	}
	return (1);
}

/*
**  ft_check_command
**  check if commande is a builtins
**  or execute commande if cmd[0] != . or /
*/

static int		ft_check_suite(t_struct *data, char **tab)
{
	if (tab[0][0] == '.')
	{
		if (ft_process(tab[0], tab, data->env) > -1)
		{
			ft_del_tab(tab);
			return (0);
		}
	}
	else if (tab[0][0] == '/')
	{
		if (ft_existe_in_path(data, &tab[0]) == 0)
		{
			ft_del_tab(tab);
			return (1);
		}
	}
	return (-1);
}

int				ft_check_command(char **line, t_struct *data, int epur)
{
	int		ret;
	char	**tab;
	char	*tmp;

	ret = 1;
	tab = NULL;
	tmp = NULL;
	if ((ft_builtins(line, data)) == 0)
		return (0);
	tab = epur_tab(*line, epur);
	if (ft_check_suite(data, tab) == -1)
		ret = ft_exec_cmd_path(data, tab, &tmp);
	ft_strdel(&tmp);
	ft_del_tab(tab);
	return (ret);
}
