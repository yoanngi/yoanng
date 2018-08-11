/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/28 12:57:46 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/11 13:15:14 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

void		print_debug(t_cmd **data, int code)
{
	t_cmd   *start;
	t_path	*path;
	int		i;

	start = *data;
	// comment for no print
	//return ;
	printf("[+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++]\n");
	printf("code = %d\n", code);
	while (start)
	{
		printf("[++++++++++++++++++++++++++++++++++]\n");
		i = 0;
		printf("rep = %s\n", start->rep);
		path = start->pathname;
		printf("PATH:\n");
		while (path)
		{
			printf("\tpathname = |%s|\n", path->name);
			path = path->next;
		}
		printf("COMMANDES:\n");
		if (start->tab_cmd != NULL)
		{
			while (start->tab_cmd[i])
			{
				printf("\ttab_cmd[%d] = %s\n", i, start->tab_cmd[i]);
				i++;
			}
		}
		printf("op_next = %d\n", start->op_next);
		printf("stdin = %d\n", start->stdin_cmd);
		printf("stdout = %d\n", start->stdout_cmd);
		printf("stderr = %d\n", start->stderr_cmd);
		printf("pid = %d\n", start->pid);
		start = start->next;
		printf("[----------------------------------]\n\n");
	}
	printf("[------------------------------------------------------------------]\n\n");
}
