/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_env.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 13:51:50 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Part 2 : print env with valeur
*/

static void		env_dir_suite(char *cpy, char *tab, t_struct *data)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], cpy, ft_strlen(cpy)) == 0)
		{
			tmp = ft_strsub(data->env[i], ft_strlen(cpy) + 1,
	ft_strlen(data->env[i]) - ft_strlen(cpy) + 1);
			if (ft_dir_exist(tmp) == 1)
				ft_putendl(tmp);
			else
				ft_error_dir(tab, "env: ");
			ft_strdel(&tmp);
		}
		i++;
	}
	ft_strdel(&tmp);
}

/*
**	Part 1 : print env with valeur
*/

static void		env_dir(char **tab, t_struct *data)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = NULL;
	if (!tab || !data)
		return ;
	cpy = ft_strdup(tab[1]);
	while (tab[1][i])
	{
		cpy[i] = ft_toupper(tab[1][i]);
		i++;
	}
	env_dir_suite(cpy, tab[1], data);
	ft_strdel(&cpy);
}

/*
**	Print all env
*/

static void		print_full_env(t_struct *data)
{
	int		i;

	i = 0;
	while (data->env[i])
	{
		ft_putendl(data->env[i]);
		i++;
	}
}

/*
**	Core env
*/

void			func_env(char **line, t_struct *data)
{
	int		len;
	char	**tmp;

	tmp = NULL;
	if (ft_strlen(*line) == 3)
		print_full_env(data);
	else
	{
		tmp = ft_strsplit(*line, ' ');
		len = ft_len_tab(tmp);
		if (len == 2)
			env_dir(tmp, data);
		else
			ft_error_dir(tmp[1], "env: ");
		ft_del_tab(tmp);
	}
}
