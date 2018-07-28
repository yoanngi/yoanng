/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/28 12:57:46 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/28 13:29:10 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

void		print_debug(t_cmd **data)
{
	t_cmd   *start;

	start = *data;
	// comment for no print
	//return ;
	printf("[++++++++++++++++++++++++++++++++++]\n");
	while (start)
	{
		printf("rep = %s\n", start->rep);
		printf("pathname = |%s|\n", start->pathname);
		printf("tab[0] = %s\n", start->tab_cmd[0]);
		printf("tab[1] = %s\n", start->tab_cmd[1]);
		printf("op_next = %d\n", start->op_next);
		printf("op_redir = %d\n\n", start->op_redir);
		start = start->next;
	}
	printf("[----------------------------------]\n\n");
}
