/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_whatdoyouwant.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 14:59:52 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 17:55:27 by xamartin    ###    #+. /#+    ###.fr     */
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
		cpy = (t_lst *)tab[hash][1] + 2;
		printf("test\n");
		printf("%s\n", cpy->cle);
		while (cpy->cle != NULL)
		{
			if (ft_strcmp(*line, cpy->cle) == 0)
			{
				ft_putstr(cpy->valeur);
				break ;
			}
			cpy = cpy->next;
		}
	}
	else
	{
		ft_putstr(*line);
		ft_putstr(": Not_found.");
	}
	ft_putstr("\n");
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
