/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   len_list.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/12 07:25:56 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/14 08:47:34 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			len_list(t_cmd *lst)
{
	t_cmd	*cpy;
	int		i;

	if (lst == NULL)
		return (0);
	cpy = lst;
	i = 0;
	while (cpy)
	{
		i++;
		cpy = cpy->next;
	}
	return (i);
}