/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_commandes.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 10:11:49 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 12:17:57 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Tous le parsing de line est fait ici
**	Retourne une liste chainee avec les differents commande, path, env, fd..
**
**	Difference entre && et ;
**	&& -> si la premiere commande echoue, la 2eme ne se fait pas
**	; -> si la premiere commande echoue, la 2 eme se fait
**
**
**  ft_nefaitrien
**	Gestion des cas d'erreur :
**  **	len line = 1 et line[0] = ;
**	**	;; -> 21sh :parse errror near ;;
**
*/

static int		ft_nefaitrien(char **line)
{
	if (ft_strlen(*line) == 0 || (ft_strlen(*line) == 1 && *line[0] == ';'))
	{
		ft_strdel(line);
		return (1);
	}
	else if (ft_strstr(*line, ";;") != NULL)
	{
		ft_putstr_fd("21sh: parse error near `;;'\n", 2);
		ft_strdel(line);
		return (1);
	}
	return (0);
}

/*
**	Fonction annexe de ft_split_commandes
*/

static int		ft_init_parsing(t_ins **new, char **line)
{
	if (ft_nefaitrien(line) == 1)
		return (1);
	if (!(*new = ft_init_ins()))
	{
		*new = clear_ins(*new);
		return (1);
	}
	return (0);
}

/*
**	Compare la commande avec les builtins et renvoie vrai ou faux
*/

static int		compare_builtins(char **builtins, t_cmd *cmd)
{
	int		i;
	int 	z;

	i = 0;
	z = 0;
	while (builtins[i])
	{
		z = ft_strcmp(builtins[i], cmd->tab_cmd[0]);
		if (z == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
**	Verifis si on a les droits et si la commandes existe
*/

static int		ft_check_arg_invalid(t_struct *data, t_ins **check)
{
	t_ins	*cpy;
	t_cmd	*cmd;

	cpy = *check;
	while (cpy)
	{
		cmd = cpy->cmd;
		while (cmd)
		{
			if ((cmd->rep == NULL && cmd->op_redir == 0)
	&& compare_builtins(data->builtins, cmd) == 1)
			{
				basic_error("commande not found: ", cmd->tab_cmd[0]);
				return (1);
			}
			if (cmd->rep != NULL && ft_access_rep(cmd->rep) != 0)
			{
				basic_error("permission denied: ", cmd->tab_cmd[0]);
				return (1);
			}
			cmd = cmd->next;
		}
		cpy = cpy->next;
	}
	return (0);
}

/*
**	Parse en fonction des ;
**	Parse en fonction des pipes et redirections
**	Verifie si les commandes existe, sont accessibles
*/

t_ins			*ft_split_commandes(char **line, t_struct *data)
{
	t_ins	*new_ins;
	t_ins	*cpy;
	char	*tmp;

	cpy = NULL;
	tmp = NULL;
	new_ins = NULL;
	if (ft_init_parsing(&new_ins, line) == 1)
		return (NULL);
	new_ins = ft_split_pvirgule(*line, new_ins);
	cpy = new_ins;
	while (cpy)
	{
		tmp = ft_strdup(cpy->str);
		cpy->cmd = ft_split_cmd(tmp, data);
		cpy = cpy->next;
	}
	if (ft_check_arg_invalid(data, &new_ins) == 1)
	{
		new_ins = clear_ins(new_ins);
		data->code_erreur = 127;
		return (NULL);
	}
	return (new_ins);
}
