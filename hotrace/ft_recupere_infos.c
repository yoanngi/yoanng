/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recupere_infos.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 14:19:32 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 17:55:06 by xamartin    ###    #+. /#+    ###.fr     */
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

void		ft_add_infos(char **line, char **cpy, t_lst *list, unsigned long **tab)
{
	t_lst			*new;
	unsigned long	hash;

	new = ft_list_new();

	hash = ft_hash(*cpy);
	list->cle = ft_strdup(*cpy);
	list->valeur = ft_strdup(*line);
	list->hash = hash;
	if (tab[hash][0] == 0)
	{
		new->cle = ft_strdup(*cpy);
		new->valeur = ft_strdup(*line);
		new->hash = hash;
		printf("insertion ! -> %p\n", &new);
		printf("insertion (next) ! -> %p\n", &new->next);
		tab[hash][0] = list->hash;
		tab[hash][1] = (unsigned long)&new->next;
		printf("tab 1 = %lx\n", tab[hash][1]);
	}
	else
		printf("collision\n");
	//ft_insert(tab, *list);
}

int			ft_recupere_infos(unsigned long **tab)
{
	char	*line;
	char	*cpy;
	t_lst	*start;
	t_lst	*list;
	int		i;

	i = 1;
	list = ft_list_new();
	start = list;
	while (get_next_line(0, &line))
	{
		if (i++ % 2 == 0)
		{
			ft_add_infos(&line, &cpy, list, tab);
			ft_strdel(&cpy);
			list->next = ft_list_new();
			list = list->next;
		}
		else
			cpy = ft_strdup(line);
		if (!ft_strcmp("", line))
			break ;
	}
	while (start)
	{
		printf("cle = %s\n", start->cle);
		printf("valeur = %s\n", start->cle);
		printf("adresse start = %p\n", &start);
		printf("adresse start->next = %p\n\n", &start->next);
		start = start->next;
	}
	ft_whatdoyouwant(tab);
//	ft_resolve(start, i);
	return (1);
}
