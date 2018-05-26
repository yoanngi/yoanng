/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clear_line.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/26 14:57:37 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/26 14:57:51 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**  Delete space and tab
*/

void		clear_line(char **line)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup(*line);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	ft_strdel(line);
	*line = ft_strdup(str + i);
}
