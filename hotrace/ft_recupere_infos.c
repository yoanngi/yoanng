/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recupere_infos.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 14:19:32 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 16:45:59 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdio.h>

long		ft_hash(char *cle, char *valeur)
{
	long	hash;

	hash = 0;
	return (hash);
}

void		ft_add_infos(char **line, char **cpy, t_lst **list, int nb)
{
	printf("clef = %s, valeur = %s, nb = %d\n", *cpy, *line, nb);
	(*list)->cle = ft_strdup(*cpy);
	(*list)->valeur = ft_strdup(*line);
	(*list)->hash = ft_hash((*list)->cle, (*list)->valeur);
	(*list)->compteur = nb;
}

int			ft_recupere_infos(void)
{
	char	*line;
	char	*cpy;
	t_lst	*start;
	t_lst	*list;
	int		i;

	i = 1;
	start = ft_list_new();
	list = start;
	while (get_next_line(0, &line))
	{
		if (i % 2 == 0)
		{
			ft_add_infos(&line, &cpy, &list, i);
			ft_strdel(&cpy);
			list->next = ft_list_new();
			list = list->next;
		}
		else
			cpy = ft_strdup(line);
		if (!ft_strcmp("", line))
			break ;
		i++;
	}
	return (ft_resolve(start, i));
}
