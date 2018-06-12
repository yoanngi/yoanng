/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_commandes.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 10:11:49 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/12 17:36:36 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
**	Tous le parsing de line est fait ici
**	Retourne une liste chainee avec les differents commande, path, env
*/

t_cmd			*ft_split_commandes(char **line, t_struct **data)
{
	t_cmd	*new;
	t_cmd	*start;
	char	*tmp;

	tmp = NULL;
	start = NULL;
	if (!(new = ft_init_commandes()))
		return (NULL);
	start = new;
	tmp = ft_strdup(*line);

	/* TEST */
	(*data)->pipe = 1;
	new->rep = ft_strdup("/bin/ls");
	new->tab_cmd = (char **)malloc(sizeof(char *) * 3);
	new->tab_cmd[0] = ft_strdup("ls");
	new->tab_cmd[1] = ft_strdup("-lRa");
	new->tab_cmd[2] = NULL;
	new->stdin_cmd = 0;
	new->stdout_cmd = 1;
	new->stderr_cmd = 0;
	new->env = (*data)->env;
	new->next = ft_init_commandes();
	new = new->next;

	new->rep = ft_strdup("/usr/bin/grep");
	new->tab_cmd = (char **)malloc(sizeof(char *) * 4);
	new->tab_cmd[0] = ft_strdup("grep");
	new->tab_cmd[1] = ft_strdup("auteurss");
	new->tab_cmd[2] = NULL;
	new->tab_cmd[3] = NULL;
	new->stdin_cmd = 1;
	new->stdout_cmd = 1;
	new->stderr_cmd = 0;
	new->env = (*data)->env;
/*
	new->next = ft_init_commandes();
	new = new->next;
	new->rep = ft_strdup("/usr/bin/sort");
	new->tab_cmd = (char **)malloc(sizeof(char *) * 3);
	new->tab_cmd[0] = ft_strdup("sort");
	new->tab_cmd[1] = NULL;
//	new->tab_cmd[1] = ft_strdup("auteur");
	new->tab_cmd[2] = NULL;
	new->stdin_cmd = 1;
	new->stdout_cmd = 0;
	new->stderr_cmd = 0;
	new->env = (*data)->env;
	new->next = ft_init_commandes();
	new = new->next;

	new->rep = ft_strdup("/usr/bin/grep");
	new->tab_cmd = (char **)malloc(sizeof(char *) * 3);
	new->tab_cmd[0] = ft_strdup("grep");
	new->tab_cmd[1] = ft_strdup("c.");
	new->tab_cmd[2] = NULL;
	new->stdin_cmd = 1;
	new->stdout_cmd = 1;
	new->stderr_cmd = 0;
	new->env = (*data)->env;
*/
	/* END TEST */

	ft_strdel(&tmp);
	return (start);
}
