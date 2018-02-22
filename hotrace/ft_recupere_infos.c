/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recupere_infos.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 14:19:32 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 15:44:34 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

void		ft_add_infos(char **line, char **cpy, t_list **list, int nb)
{
	(*list)->cle = ft_strdup(*cpy);
	(*list)->valeur = ft_strdup(*line);
	(*list)->hash = ft_hash((*list)->cle, (*list)->valeur);
	(*list)->compteur = nb - 1;
}

int			ft_recupere_infos(void)
{
	char	*line;
	char	*cpy;
	t_list	*start;
	t-list	*list;
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
			i++;
			list = ft_list_new();
			list = list->next;
		}
		else
			cpy = ft_strdup(line);
		free(line);
	}
	ft_resolv(start);
	return (0);
}
