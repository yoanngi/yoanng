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
**	Return good line in env
*/

char		*ft_return_env(char *str, t_struct *data)
{
	char	*tmp;
	int		i;
	size_t	len;

	tmp = NULL;
	i = 0;
	len = ft_strlen(str);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], str, len) == 0)
		{
			tmp = ft_strsub(data->env[i], (int)len + 1,
	ft_strlen(data->env[i] - len - 1));
			ft_strdel(&str);
			return (tmp);
		}
		i++;
	}
	ft_strdel(&str);
	return (NULL);
}
