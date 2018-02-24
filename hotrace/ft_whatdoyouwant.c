/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_whatdoyouwant.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 14:59:52 by yoginet      #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2018/02/24 14:43:06 by yoginet     ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2018/02/23 17:55:27 by xamartin    ###    #+. /#+    ###.fr     */
>>>>>>> 123b871fa5a52f9b41a3cd9985a2e876316cfca6
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
<<<<<<< HEAD
		cpy = (t_lst *)tab[hash][1];
		while (cpy)
=======
		cpy = (t_lst *)tab[hash][1] - 16;
		printf("test ft_existe, adresse donne a cpy = %p\n", &cpy);
		printf("|%s|\n", cpy->cle);
		printf("|%s|\n", cpy->valeur);
		while (cpy->cle != NULL)
>>>>>>> 123b871fa5a52f9b41a3cd9985a2e876316cfca6
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
		ft_putstr(": Not_found.\n");
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
