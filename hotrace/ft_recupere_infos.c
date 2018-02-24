/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recupere_infos.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 14:19:32 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/24 14:43:07 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

long		ft_hash(char *cle)
{
	long	hash;
	int		i;

	i = 0;
	hash = 0;
	while (cle[i])
	{
		hash += cle[i];
		i++;
	}
	i = 0;
	while (cle[i])
	{
		hash = ((hash << 5) + hash) + cle[i] + 1;
		i++;
	}
	hash = hash % 10000000;
	if (hash < 0)
		hash = -hash;
	return (hash);
}

void		ft_add_infos(char **line, char **cpy, unsigned long **tab)
{
	unsigned long	hash;
	t_lst			*list;
	t_lst			*col;

	hash = ft_hash(*cpy);
	if (tab[hash][0] == 0)
	{
		list = ft_list_new();
		list->cle = ft_strdup(*cpy);
		list->valeur = ft_strdup(*line);
		list->hash = hash;
		tab[hash][0] = (unsigned long)hash;
		tab[hash][1] = (unsigned long)list;
	}
	else
	{
		col = (t_lst *)tab[hash][1];
		while (col->next)
			col = col->next;
		col->next = ft_list_new();
		col->cle = ft_strdup(*cpy);
		col->valeur = ft_strdup(*line);
		col->hash = hash;
	}
}

int			ft_recupere_infos(unsigned long **tab)
{
	char	*line;
	char	*cpy;
	int		i;

	i = 1;
	while (get_next_line(0, &line))
	{
		if (i++ % 2 == 0)
		{
			ft_add_infos(&line, &cpy, tab);
			ft_strdel(&cpy);
		}
		else
			cpy = ft_strdup(line);
		if (!ft_strcmp("", line))
			break ;
		free(line);
	}
	ft_whatdoyouwant(tab);
	return (1);
}
