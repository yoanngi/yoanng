/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execute.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 14:30:14 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 15:53:07 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Fonction pour print la variable env
*/
/****************************************************/
/*
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
*/
/****************************************************/

/*
**	Recupere la commande passer en parametre et la variable env
*/

void		ft_execute(char **line, t_struct *data)
{
	printf("data->path = %s\n", data->path);
	printf("data->pwd = %s\n", data->pwd);
	printf("data->tab_path[0] = %s\n", data->tab_path[0]);
	printf("data->tab_path[1] = %s\n", data->tab_path[1]);
	printf("data->tab_path[2] = %s\n", data->tab_path[2]);
	printf("data->tab_path[3] = %s\n", data->tab_path[3]);
	printf("line = %s\n", *line);
}
