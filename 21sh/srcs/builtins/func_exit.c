/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_exit.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 12:19:36 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			func_exit(t_struct *data, t_cmd *lst)
{
	int ret;

	ret = 0;
	if (lst->tab_cmd[1] == NULL)
		ret = 0;
	else
		ret = ft_atoi(lst->tab_cmd[1]);
	data->code_erreur = ret;
	return (-1);
}
