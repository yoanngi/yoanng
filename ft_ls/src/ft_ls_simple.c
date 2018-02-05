/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_simple.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 15:09:03 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_ls_in_order(t_lst **print)
{
	t_lst *clear;

	clear = *print;
	while (*print)
	{
		ft_putstr((*print)->name);
		ft_putstr("\n");
		*print = (*print)->next;
	}
	//ft_clean(&clear);
}

static t_lst		*ft_class_print(t_lst **data)
{
	t_lst	*cpy;
	t_lst	*ret;
	int		i;
	int		cmp;

	i = 0;
	cmp = 0;
	cpy = *data;
	ret = *data;
	cpy = cpy->next;
	if (!(*data) || (*data)->name == NULL || (cpy->name == NULL && cpy->next == NULL))
		return (ret);
//	printf("HERE %s \n", (*data)->name);
	while((*data)->name != NULL && cpy->name != NULL)
	{
//		printf("Avant : data-> %s | cpy-> %s\n", (*data)->name, cpy->name);
		if (ft_strcmp((*data)->name, cpy->name) > 0)
		{
//			printf("SWAP\n");
			ft_swap_lst(data, &cpy);
			i = 1;
		}
//		printf("Apres : data-> %s | cpy-> %s\n", (*data)->name, cpy->name);
		cmp++;
		if (cpy->next != NULL || (*data)->next != NULL)
		{
//			printf("cpy->next != NULL\n");
			cpy = cpy->next;
//			printf ("cpy->next->name = %s\n", cpy->name);
			*data = (*data)->next;
		}
		else if (cmp > 2 && i == 1)
		{
			free(cpy);
			ft_class_print(&ret);
		}
	}
//	printf("i = %d, cmp = %d\n", i, cmp);
	if (cmp > 2 && i == 1)
		ft_class_print(&ret);
//	printf("Sortie de la fonction\n");
	return(ret);

	// segfault a gerer
}

void	ft_ls_simple(char *target)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*data;
	t_lst		*print;
	t_lst		*print2;

	data = ft_lstnew_ls();
	print = data;
	print2 = data;
	if ((dir = opendir(target)) == NULL)
	{
		perror("Impossible d'ouvrir le fichier\n");
		exit(1);
	}
	while ((fichierlu = readdir(dir)) != NULL)
	{
		if ((ft_strcmp(fichierlu->d_name, "..") != 0) &&
	(fichierlu->d_name[0] != '.'))
		{
			data->name = ft_strdup(fichierlu->d_name);
			data->next = ft_lstnew_ls();
			data = data->next;
		}
	}
	closedir(dir);
	ft_class_print(&print);
//	printf("Fonction qui print !\n");
	ft_print_ls_in_order(&print2);
}
