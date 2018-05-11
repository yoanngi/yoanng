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
