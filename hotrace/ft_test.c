/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_test.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 12:10:28 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 14:58:08 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

void		ft_test_acces(unsigned long long **tab, int hash)
{
	t_lst			*list;

	printf("**********************Print*************************\n\n");
	list = (t_lst *)tab[hash][1] + 2;
	printf("adresse = %p\n", &list);
	list = list->next;
	printf("valeur : test->cle = %s\n", list->cle);
	printf("valeur : test->valeur = %s\n", list->valeur);
}
