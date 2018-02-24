/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_whatdoyouwant.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 14:59:52 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/24 14:43:06 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

void				ft_existe(char **line, unsigned long **tab)
{
	t_lst			*cpy;
	unsigned long	hash;

	hash = ft_hash(*line);
	if (tab[hash][1] != 0)
	{
		cpy = (t_lst *)tab[hash][1];
		while (cpy)
		{
			if (ft_strcmp(*line, cpy->cle) == 0)
			{
				ft_putstr(cpy->valeur);
				ft_putstr("\n");
				return ;
			}
			cpy = cpy->next;
			if (cpy->cle == NULL || cpy->valeur == NULL)
				return ;
		}
	}
	else
	{
		ft_putstr(*line);
		ft_putstr(": Not found.\n");
	}
}

void				ft_whatdoyouwant(unsigned long **tab)
{
	char			*line;

	while (get_next_line(0, &line))
	{
		if (!ft_strcmp("", line))
			break ;
		ft_existe(&line, tab);
	}
}
