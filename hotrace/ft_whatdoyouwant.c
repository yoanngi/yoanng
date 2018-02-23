/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_whatdoyouwant.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 14:59:52 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 15:55:22 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

void	ft_existe(char **line, unsigned long long **tab)
{
	t_lst				*cpy;
	unsigned long long	hash;

	hash = ft_hash(*line);
	if (tab[hash][1] != 0)
	{
		cpy = (t_lst *)tab[hash][1] + 2;
		while (cpy)
		{
			if (cpy->next == NULL)
				break ;
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

void	ft_whatdoyouwant(unsigned long long **tab)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (!ft_strcmp("", line))
			break ;
		ft_existe(&line, tab);
	}
}
