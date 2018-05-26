/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_env_print.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/11 15:17:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 15:18:05 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Print all env
*/

void		print_full_env(t_struct *data)
{
	int		i;

	i = 0;
	if (data->env == NULL)
		return ;
	while (data->env[i])
	{
		ft_putendl(data->env[i]);
		i++;
	}
}

/*
**	Print usage
*/

void		ft_print_usage(char *str)
{
	ft_putstr("env: illegal option -- ");
	ft_putendl(ft_strstr(str, "-i") + 1);
	ft_putstr("env [-i] [name=value]... [utility [argument...]]\n");
}

/*
**	return 0 if option -i illiegal
*/

int			ft_option_i(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == 'i')
			i++;
		else
			return (0);
	}
	return (1);
}

/*
**	Execute commande env
*/

int			ft_env_cmd(t_struct *data, char **tab, int i, int x)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_strjoin(data->tab_path[x], "/");
	tmp2 = ft_strjoin(tmp, tab[i]);
	ft_del_tab_index(tab, i);
	ft_process(tmp2, tab, data->env_tmp);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (0);
}

/*
**	Execute rep
*/

int			ft_env_rep(t_struct *data, char **tab, int i)
{
	char	*path;
	char	*cmd;

	path = ft_return_path(tab[i]);
	cmd = ft_strdup(tab[i] + ft_strlen(path) + 1);
	ft_del_tab_index(tab, i);
	i = 0;
	if (good_path(tab[0], cmd, 1) == 1)
	{
		ft_strdel(&path);
		path = ft_strdup(tab[0]);
		ft_strdel(&tab[0]);
		tab[0] = ft_strdup(cmd);
		ft_process(path, tab, data->env_tmp);
	}
	ft_strdel(&path);
	ft_strdel(&cmd);
	return (0);
}
