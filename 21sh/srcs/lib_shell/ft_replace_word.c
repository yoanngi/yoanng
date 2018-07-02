/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_line.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/21 10:09:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 12:12:19 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** Remplace word par replace dans str
** Retourne 1 si erreur
** Retourne 0 si ok
*/

int			ft_replace_word(char **str, char *word, char *replace)
{
	char	*start;
	char	*tmp;
	int		i;

	start = NULL;
	tmp = NULL;
	i = 0;
	if (!*str || !word || !replace)
		return (1);
	start = ft_strstr(*str, word);
	tmp = ft_strsub(*str, 0, ft_strlen(*str) - ft_strlen(start));
	i = ft_strlen(tmp);
	start = ft_strjoin(tmp, replace);
	ft_strdel(&tmp);
	tmp = ft_strsub(*str, i + ft_strlen(word), ft_strlen(*str) - (i + ft_strlen(word)));
	ft_strdel(str);
	*str = ft_strjoin(start, tmp);
	ft_strdel(&tmp);
	ft_strdel(&start);
	return (0);
}
