/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_pvirgule.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 14:38:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/14 15:20:26 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		ft_split_pvirgule(char *line, t_ins **lst)
{
	int		i;
	int		j;
	int		quote;

	i = 0;
	j = 0;
	quote = 0;
	while (line[i])
	{
		if ((line[i] == '\'' || line[i] == '\"') && quote == 0)
			quote = 1;
		if ((line[i] == '\'' || line[i] == '\"') && quote == 1)
			quote = 0;
		if (line[i] == ';' && quote == 0)
		{
			(*lst)->str = ft_strsub(line, j, i);
			j = i;
			lst->next = ft_init_cmd();
			lst = lst->next;
		}
		i++;
	}
	(*lst)->str = ft_strsub(line, j, i);
}
