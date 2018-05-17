/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_env.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 15:25:43 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	No options
*/

static void		ft_env_suite(t_struct *data, char **tab, int j)
{
	int		exec;
	int		i;
	char	*tmp;

	exec = -1;
	i = 0;
	tmp = NULL;
	while (data->tab_path[i])
	{
		tmp = ft_add_line(data->tab_path[i], &tab[j], data);
		if ((exec = ft_process(tmp, tab + j, data->env)) > -1)
		{
			ft_strdel(&tmp);
			return ;
		}
		ft_strdel(&tmp);
		i++;
	}
	return ;
}

/*
**	Probleme de segfault a gerer + norme
*/

static void		ft_env(t_struct *data, char **tab, int j)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (tab[j][0] == '$')
		tab[j] = ft_return_env(tab[j], data);
	if (tab[j] == NULL)
		ft_env(data, tab, j + 1);
	while (data->tab_path[i])
	{
		tmp = ft_add_line(data->tab_path[i], &tab[j], data);
		if (good_path(tmp, tab[j]) == 1)
		{
			ft_env_suite(data, tab, j);
			ft_strdel(&tmp);
			return ;
		}
		ft_strdel(&tmp);
		i++;
	}
	print_full_env(data);
	while (tab[j])
	{
		ft_putendl(tab[j]);
		j++;
	}
}

/*
**	Option -i
*/

static void		ft_env_i(t_struct *data, char *line, char **tab, int i)
{
	if (ft_strcmp(line, "env -i") == 0)
		return ;
	if (ft_len_tab(tab) == i)
		return ;
	else
		ft_env(data, tab, i + 1);
}

/*
**	Core env
*/

void			func_env(char **line, t_struct *data)
{
	char	**tmp;
	int		i;
	size_t	len;

	tmp = NULL;
	i = 0;
	tmp = ft_strsplit(*line, ' ');
	len = ft_len_tab(tmp);
	while (tmp[i] && ft_strcmp(tmp[i], "env") == 0)
		i++;
	if ((int)len == i)
	{
		print_full_env(data);
		return ;
	}
	if (ft_strcmp(tmp[i], "-i") == 0)
		ft_env_i(data, *line, tmp, i);
	else if (ft_strcmp(tmp[i], "-i") != 0 && ft_strstr(tmp[i], "-i") != NULL)
		ft_print_usage(tmp[i]);
	else
		ft_env(data, tmp, i);
	ft_del_tab(tmp);
}
