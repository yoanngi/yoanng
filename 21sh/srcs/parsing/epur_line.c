/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   epur_line.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 15:29:32 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 17:01:41 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Supprime les espaces avant
*/

static char		*clean_before(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	new = ft_strsub(str, i, ft_strlen(str) - i);
	return (new);
}

/*
**	Supprime les espaces apres
*/

static char		*clean_next(char *str)
{
	int		i;
	char	*new;

	i = ft_strlen(str) - 1 ;
	new = NULL;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
		i--;
	new = ft_strsub(str, 0, i + 1);
	return (new);
}

/*
**	Supprime les espaces entre
*/

static int		clean_bet_suite(char *str, int i, char **new, char **tmp)
{
	int		q;

	q = 0;
	if (i + 2 == ft_strlen(str))
		q = 1;
	if (str[i] == ' ' && str[i + 1] == ' ')
	{
		*new = ft_strsub(str, 0, i);
		while (str[i] == ' ')
			i++;
		*tmp = ft_strsub(str, i - 1, ft_strlen(str) - (i - 1));
		q = 1;
	}
	return (q);
}

static int		*clean_between(char **string, int i)
{
	char	*tmp;
	char	*new;
	char	*str;
	int		q;

	tmp = NULL;
	new = NULL;
	str = ft_strdup(*string);
	q = 0;
	while (q == 0)
	{
		q = clean_bet_suite(str, i, &new, &tmp);
		i++;
	}
	ft_strdel(string);
	*string = ft_strjoin(new, tmp);
	ft_strdel(&tmp);
	ft_strdel(&new);
	ft_strdel(&str);
	if (ft_strstr(*string, "  ") != NULL)
		clean_between(string, 0);
	return (0);
}

/*
**	Supprime les espaces inutiles
*/

int				clear_line(char **line)
{
	char	*before;
	char	*next;

	before = NULL;
	next = NULL;
	before = clean_before(*line);
	next = clean_next(before);
	ft_strdel(line);
	*line = ft_strdup(next);
	ft_strdel(&before);
	ft_strdel(&next);
	if (ft_strstr(*line, "  ") != NULL)
		clean_between(line, 0);
	return (0);
}
