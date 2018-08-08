/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   insert_cmd_simple.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/08 15:04:18 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/08 15:40:49 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			insert_cmd_simple(t_struct *data, t_cmd **lst, char *str)
{
	(*lst)->tab_cmd = split_cmd(str, 0);
	chose_rep(data, lst, 0);
	(*lst)->env = ft_duplicate_tab(data->env);
	return (0);
}
