/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_new.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 15:21:39 by yoginet      #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2018/02/24 13:04:36 by yoginet     ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2018/02/22 16:05:12 by xamartin    ###    #+. /#+    ###.fr     */
>>>>>>> 123b871fa5a52f9b41a3cd9985a2e876316cfca6
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
