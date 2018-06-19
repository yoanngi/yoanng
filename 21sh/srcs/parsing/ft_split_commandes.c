/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_commandes.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 10:11:49 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 15:51:39 by yoginet     ###    #+. /#+    ###.fr     */
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
*/

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

t_ins			*ft_split_commandes(char **line, t_struct *data)
{
	t_ins	*new_ins;
	t_ins	*cpy;
	t_cmd	*new_cmd;
	int		err;

	err = 0;
	cpy = NULL;
	if (ft_error_enter(line) == 1)
		return (NULL);
	if ((!(new_ins = ft_init_ins())) || (!(new_cmd = ft_init_cmd())))
		err = 1;
	if (err == 1)
	{
		new_ins = clear_ins(new_ins);
		new_cmd = clear_cmd(new_cmd);
		return (NULL);
	}
	new_ins = ft_split_pvirgule(*line, new_ins);
	cpy = new_ins;
	while (cpy)
	{
		cpy->cmd = ft_split_cmd(cpy->str, data);
		cpy = cpy->next;
	}
	return (new_ins);
}
