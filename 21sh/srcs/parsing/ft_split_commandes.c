/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_commandes.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 10:11:49 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 16:47:35 by yoginet     ###    #+. /#+    ###.fr     */
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
**	Gestion des cas d'erreur :
**	;; -> 21sh :parse errror near ;;
**
**  Ne fait rien :
**  len line = 1 et line[0] = ;
*/

static int		ft_nefaitrien(char **line)
{
	if (ft_strlen(*line) == 0 || (ft_strlen(*line) == 1 && *line[0] == ';'))
	{
		ft_strdel(line);
		return (1);
	}
	return (0);
}

static int		ft_error_enter(char **line)
{
	if (ft_strstr(*line, ";;") != NULL)
	{
		ft_putstr_fd("21sh: parse error near `;;'\n", 2);
		ft_strdel(line);
		return (1);
	}
	return (0);
}

static int      ft_init_parsing(t_ins **new, char **line)
{
	if (ft_error_enter(line) == 1 || ft_nefaitrien(line) == 1)
		return (1);
	if (!(*new = ft_init_ins()))
	{
		*new = clear_ins(*new);
		return (1);
	}
    return (0);
}

t_ins			*ft_split_commandes(char **line, t_struct *data)
{
	t_ins	*new_ins;
	t_ins	*cpy;
	int		err;
	char	*tmp;

	err = 0;
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
	return (new_ins);
}
