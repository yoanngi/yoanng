/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_commandes.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 10:17:46 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/11 17:42:50 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_cmd			*ft_init_commandes(void)
{
	t_cmd	*new;

	new = NULL;
	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (new == NULL)
		return (NULL);
	new->rep = NULL;
	new->tab_cmd = NULL;
//	stdin_cmd = 0;
//	stdout_cmd = 0;
//	stderr_cmd = 0;
	new->env = NULL;
	new->next = NULL;
	return (new);
}
