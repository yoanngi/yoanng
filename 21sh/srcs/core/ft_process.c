/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_process.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/13 15:38:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 16:31:19 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Fonction pour une execution simple d'une commande
**	return : Valeur de retour de la commande
*/

int				ft_process(t_cmd *data)
{
	pid_t	father;
	int		exec;
	int		status;

	father = fork();
	exec = -1;
	if (father < 0)
	{
		ft_error_fork(father);
		exit(EXIT_FAILURE);
	}
	else if (father == 0)
	{
		exec = execve(data->rep, data->tab_cmd, data->env);
		if (exec == -1)
			kill(father, 0);
		return (exec);
	}
	else
		waitpid(father, &status, 0);
	return (WEXITSTATUS(status));
}
