/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execute.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 14:30:14 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 15:21:35 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Fonction pour print la variable env
*/

static void		print_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		printf("Line %d = %s\n", i, env[i]);
		i++;
	}
}

/*
**	Recupere la commande passer en parametre et la variable env
*/

void		ft_execute(char **line, char **env)
{
	print_env(env);
	execve(*line, NULL, NULL);
}
