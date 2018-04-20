/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 10:06:21 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 13:00:45 by yoginet     ###    #+. /#+    ###.fr     */
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
	if (!*tab)
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

/*
**	Search c && d in string
*/

int			ft_search_cd(char *str, char c, char d)
{
	int 	i;
	int		prime;

	i = 0;
	prime = 0;
	if (ft_strlen(str) <= 1  && str[0] == c)
		return (1);
	while (str[i])
	{
		if (str[i] == c)
		{
			prime = i;
			i++;
			while(str[i] || str[i] != d)
				i++;
			if (str[i] == d)
				i = prime + 1;
			else
				return (1);
		}
		i++;
	}
	return (0);
}