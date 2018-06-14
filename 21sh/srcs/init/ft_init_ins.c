/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_ins.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 15:40:13 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/14 15:44:47 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

t_ins			*ft_init_ins(void)
{
	t_ins	*new;

	new = NULL;
	new = (t_ins *)malloc(sizeof(t_ins));
	if (new == NULL)
		return (NULL);
	new->cmd = NULL;
	new->next = NULL;
	return (new);
}

t_ins			*clear_ins(t_ins *start)
{
	t_ins	*clear;
	t_ins	*cpy;

	clear = start;
	cpy = NULL;
	while (clear)
	{
		ft_strdel(&clear->cmd);
		cpy = clear;
		clear = clear->next;
		free(cpy);
		cpy = NULL;
	}
	free(clear);
	clear = NULL;
	return (NULL);
}
