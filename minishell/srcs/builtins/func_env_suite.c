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
	ft_putstr("usage: env [-i]\n");
	ft_putstr("               [name=value ...][utility [argument ...]]\n");
}

/*
**	Search options i
*/

int			ft_options_i(char **tmp, int i)
{
	while (tmp[i])
	{
		if (ft_strcmp(tmp[i], "-i") == 0)
			return (1);
		i++;
	}
	return (0);
}
