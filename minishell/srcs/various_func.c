/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   various_func.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 10:06:21 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 14:25:09 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Delete tab and return NULL
*/

char		*ft_del_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

/*
**	Add commande in end of path
*/

char		*ft_add_line(char *str, char *add)
{
	char	*tmp;
	char	*new;

	tmp = ft_strjoin(str, "/");
	new = ft_strjoin(tmp, add);
	ft_strdel(&tmp);
	return (new);
}

/*
**	Return len tab
*/

int			ft_len_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

/*
**	Directory exist of not
*/

int			ft_dir_exist(char *path)
{
	DIR		*dir;

	if (!(dir = opendir(path)))
		return (0);
	closedir(dir);
	return (1);
}