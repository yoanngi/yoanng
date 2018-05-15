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
**	Core env
*/

void			func_env(char **line, t_struct *data)
{
	char	**tmp;

	tmp = NULL;
	if (data->env == NULL)
		return ;
	if (ft_strlen(*line) == 3)
		print_full_env(data);
	else
	{
		tmp = ft_strsplit(*line, ' ');
		if (ft_strcmp(tmp[1], "-iv") == 0)
			ft_putstr("-iv\n");
		if (ft_strcmp(tmp[1], "-i") == 0)
			ft_putstr("-i\n");
		if (ft_strcmp(tmp[1], "-u") == 0)
			ft_putstr("-u\n");
		else
			env_dir(tmp, data);
		ft_del_tab(tmp);
	}
}
