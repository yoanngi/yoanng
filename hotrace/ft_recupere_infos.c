/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recupere_infos.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 14:19:32 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 14:44:47 by yoginet     ###    #+. /#+    ###.fr     */
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

void		ft_add_infos(char **line, char **cpy, t_lst **list, int nb)
{
	(*list)->cle = ft_strdup(*cpy);
	(*list)->valeur = ft_strdup(*line);
	(*list)->hash = ft_hash((*list)->cle);
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
	ft_resolve(start, i);
	return (1);
}
