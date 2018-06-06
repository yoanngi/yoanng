/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_env.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 13:59:40 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
**	Check if commande existe int dir data->tab_path and return index
*/

static int		ft_is_commande(t_struct *data, char *str)
{
	int		i;

	i = 0;
	while (data->tab_path[i])
	{
		if (good_path(data->tab_path[i], str, 0) == 1)
			return (i);
		i++;
	}
	return (-1);
}

/*
**	Call good func if cmd, rep, variable ... of print error
*/

static void		ft_env_suite(t_struct *data, char **tab, int i, int x)
{
	while (tab[i])
	{
		if ((x = ft_is_commande(data, tab[i])) != -1)
		{
			ft_env_cmd(data, tab, i, x);
			return ;
		}
		else if (tab[i][0] == '/' || tab[i][0] == '.')
		{
			ft_env_rep(data, tab, i);
			return ;
		}
		else if (ft_strstr(tab[i], "=") != NULL)
		{
			data->env_tmp = ft_insert_in_tab(data->env_tmp, tab[i]);
		}
		else
		{
			ft_error_dir("env : ", tab[i]);
			return ;
		}
		i++;
	}
	ft_print_tab(data->env_tmp);
}

/*
**	Check if tab[i] is NULL or if option -i is ok
**	if needed, print usage or go ft_env_suite
*/

static void		ft_env(t_struct *data, char **tab, int i)
{
	while (tab[i])
	{
		if (tab[i] == NULL)
			return ;
		else if (ft_option_i(tab[i]) == 1)
			data->option_i_env = 1;
		else if (ft_strcmp(tab[i], "env") != 0)
		{
			if (tab[i][0] == '-')
				ft_print_usage(tab[i]);
			else
			{
				if (data->option_i_env == 0)
					data->env_tmp = ft_duplicate_tab(data->env);
				ft_env_suite(data, tab, i, 0);
			}
			return ;
		}
		i++;
	}
}

/*
**	Core env
*/

void			func_env(char **line, t_struct *data)
{
	char	**tab;
	int		i;

	tab = NULL;
	i = 0;
	data->option_i_env = 0;
	data->env_tmp = ft_del_tab(data->env_tmp);
	ft_check_line(data, line, 0);
	tab = ft_strsplit(*line, ' ');
	while (tab[i] && (ft_strcmp(tab[i], "env") == 0 ||
	ft_strcmp(tab[i], "/usr/bin/env") == 0))
		i++;
	if (ft_len_tab(tab) == i)
	{
		ft_del_tab(tab);
		print_full_env(data);
		return ;
	}
	ft_env(data, tab, i);
	tab = ft_del_tab(tab);
	data->env_tmp = ft_del_tab(data->env_tmp);
}
