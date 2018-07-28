/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_line_vide.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 12:06:01 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/28 10:48:57 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			ft_check_line_vide(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++; 
	}
	return (0);
}
