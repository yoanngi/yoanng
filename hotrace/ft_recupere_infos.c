/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recupere_infos.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 14:19:32 by yoginet      #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2018/02/24 14:43:07 by yoginet     ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2018/02/23 17:55:06 by xamartin    ###    #+. /#+    ###.fr     */
>>>>>>> 123b871fa5a52f9b41a3cd9985a2e876316cfca6
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

<<<<<<< HEAD
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
=======
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
>>>>>>> 123b871fa5a52f9b41a3cd9985a2e876316cfca6
}

int			ft_recupere_infos(unsigned long **tab)
{
	char	*line;
	char	*cpy;
	int		i;

	i = 1;
<<<<<<< HEAD
=======
	list = ft_list_new();
	start = list;
>>>>>>> 123b871fa5a52f9b41a3cd9985a2e876316cfca6
	while (get_next_line(0, &line))
	{
		if (i++ % 2 == 0)
		{
<<<<<<< HEAD
			ft_add_infos(&line, &cpy, tab);
=======
			ft_add_infos(&line, &cpy, list, tab);
>>>>>>> 123b871fa5a52f9b41a3cd9985a2e876316cfca6
			ft_strdel(&cpy);
		}
		else
			cpy = ft_strdup(line);
		if (!ft_strcmp("", line))
			break ;
<<<<<<< HEAD
		free(line);
	}
	ft_whatdoyouwant(tab);
=======
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
>>>>>>> 123b871fa5a52f9b41a3cd9985a2e876316cfca6
	return (1);
}
