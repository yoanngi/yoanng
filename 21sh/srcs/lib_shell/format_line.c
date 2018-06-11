/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_line.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/21 10:09:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/11 11:06:50 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
**	incremente i de la bonne valeur
*/

static int		ft_incremente_i(char *str, int i)
{
	int j;

	j = 0;
	if (str[i] == '\'')
	{
		while (str[i] != '\'')
		{
			if ((size_t)i == ft_strlen(str))
				return (j);
			i++;
			j++;
		}
	}
	else if (str[i] == '\"')
	{
		while (str[i] != '\"')
		{
			if ((size_t)i == ft_strlen(str))
				return (j);
			i++;
			j++;
		}
	}
	return (j);
}

/*
**	If epur = 1 -> no epur and return tab
**	Epur string ' or "
*/

char			**epur_tab(char *line, int epur)
{
	int		i;
	char	**tab;
	char	*tmp;

	i = 0;
	tmp = NULL;
	tab = ft_strsplit(line, ' ');
	if (epur == 1)
		return (tab);
	while (tab[i])
	{
		if ((tab[i][0] == '\'' && tab[i][ft_strlen(tab[i]) - 1] == '\'') ||
	(tab[i][0] == '\"' && tab[i][ft_strlen(tab[i]) - 1] == '\"'))
		{
			tmp = ft_strdup(tab[i]);
			ft_strdel(&tab[i]);
			tab[i] = ft_strsub(tmp, 1, ft_strlen(tmp) - 2);
			ft_strdel(&tmp);
		}
		i++;
	}
	return (tab);
}

/*
**	Insert good valeur (replace ~ or $)
*/

void			ft_check_line(t_struct *data, char **line, int i)
{
	char	*str;

	str = ft_strdup(*line);
	i = 0;
	while (str[i])
	{
		if (str[i] == '~')
			i += ft_insert_tild(data, &str, i);
		else if (str[i] == '$')
			i += ft_insert_dollar(data, &str, i);
		else if (str[i] == '\'' || str[i] == '\"')
			i += ft_incremente_i(str, i);
		i++;
	}
	ft_strdel(line);
	*line = ft_strdup(str);
	ft_strdel(&str);
}
