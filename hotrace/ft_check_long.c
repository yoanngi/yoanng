/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_long.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 16:16:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 17:52:48 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

int		ft_hereornot(char **line, t_lst **data)
{
	t_lst	*cpy;

	cpy = *data;
	while (cpy->valeur != NULL)
	{
		if (ft_strcmp(cpy->cle, *line) == 0)
		{
			ft_putstr(cpy->valeur);
			ft_putstr("\n");
			return (0);
		}
		cpy = cpy->next;
	}
	return (1);
}

int		ft_check_long(int i, t_lst *start)
{
	char	*line;

	if (i > 400)
		return (0);
	else
	{
		while (get_next_line(0, &line))
		{
			if (!ft_strcmp("", line))
				break ;
			if (ft_hereornot(&line, &start) == 1)
			{
				ft_putstr(line);
				ft_putstr(": Not found.\n");
			}
			ft_strdel(&line);
		}
	}
	return (1);
}
