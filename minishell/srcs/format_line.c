/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_line.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/21 10:09:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 13:21:00 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Delete char (index in string = target)
*/

static char		*ft_delete_char(char *str, int target)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(str);
	tmp = ft_strnew((int)len - 1);
	ft_strncpy(tmp, str, target);
	while (target < (int)len)
	{
		tmp[target] = str[target + 1];
		target++;
	}
	tmp[target] = '\0';
	ft_strdel(&str);
	return (tmp);
}

/*
**	If epur = 1 -> no epur and return tab
**	Epur string ' or "
*/

char			**epur_tab(char *line, int epur)
{
	int		i;
	int		j;
	char	**tab;

	i = 1;
	tab = NULL;
	tab = ft_strsplit(line, ' ');
	if (epur == 1)
		return (tab);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '\'' || tab[i][j] == '\"')
				tab[i] = ft_delete_char(tab[i], j);
			j++;
		}
		i++;
	}
	return (tab);
}
