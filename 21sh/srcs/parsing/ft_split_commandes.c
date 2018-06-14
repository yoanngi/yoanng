/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_commandes.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 10:11:49 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/14 15:46:12 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
**	Tous le parsing de line est fait ici
**	Retourne une liste chainee avec les differents commande, path, env, fd..
**
**	Difference entre && et ;
**	&& -> si la premiere commande echoue, la 2eme ne se fait pas
**	; -> si la premiere commande echoue, la 2 eme se fait
*/

t_cmd			*ft_split_commandes(char **line, t_struct **data)
{
	t_ins	*new;
	t_cmd	*new2;

	(void)line;
	(void)data;
	if (!(new = ft_init_ins()))
		return (NULL);
	if (!(new2 = ft_init_cmd()))
		return (NULL);
	//ft_split_pvirgule(*line, &new);
	//print_debug(new)
	//ft_split_cmd(&new, &new2);
	return (new2);
}

/* old test */
/*
	new->rep = ft_strdup("/bin/ls");
	new->pathname = NULL;
	new->tab_cmd = (char **)malloc(sizeof(char *) * 3);
	new->tab_cmd[0] = ft_strdup("ls");
	new->tab_cmd[1] = ft_strdup("-lRa");
	new->tab_cmd[2] = NULL;
	new->op_redir = 0;
	new->op_next = 1;
	new->stdin_cmd = 0;
	new->stdout_cmd = 1;
	new->stderr_cmd = 0;
	new->env = (*data)->env;
	new->next = ft_init_commandes();
	new = new->next;

	new->rep = ft_strdup("/usr/bin/grep");
	new->pathname = ft_strdup("fichiertest.txt");
	new->tab_cmd = (char **)malloc(sizeof(char *) * 4);
	new->tab_cmd[0] = ft_strdup("grep");
	new->tab_cmd[1] = ft_strdup("auteur");
	new->tab_cmd[2] = NULL;
	new->tab_cmd[3] = NULL;
	new->op_redir = 3;
	new->op_next = 1;
	new->stdin_cmd = 1;
	new->stdout_cmd = 1;
	new->stderr_cmd = 0;
	new->env = (*data)->env;
	
	new->next = ft_init_commandes();
	new = new->next;
	new->rep = ft_strdup("/usr/bin/wc");
	new->pathname = NULL;
	new->tab_cmd = (char **)malloc(sizeof(char *) * 3);
	new->tab_cmd[0] = ft_strdup("wc");
	new->tab_cmd[1] = ft_strdup("-l");
	new->tab_cmd[2] = NULL;
	new->tab_cmd[3] = NULL;
	new->op_next = 0;
	new->op_redir = 0;
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

