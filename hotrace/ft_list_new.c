/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_new.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 15:21:39 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 15:59:12 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

t_lst		*ft_list_new(void)
{
	t_lst		*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->cle = NULL;
	new->valeur = NULL;
	new->hash = 0;
	new->compteur = 0;
	new->next = NULL;
	return (new);
}
