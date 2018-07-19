/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_cmd.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 12:12:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 16:56:40 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int		clear_quote_suite(char **tmp, int i, char **new, char **new2)
{
	if (i == 0 && ft_strlen(*tmp) > 1)
	{
		*new = ft_strsub(*tmp, 1, ft_strlen(*tmp) - 1);
		ft_strdel(tmp);
		*tmp = ft_strdup(*new);
	}
	else if (i == 0 && ft_strlen(*tmp) == 1)
		return (1);
	else if (i == ft_strlen(*tmp) - 1)
	{
		*new = ft_strsub(*tmp, 0, ft_strlen(*tmp) - 1);
		ft_strdel(tmp);
		*tmp = ft_strdup(*new);
	}
	else
	{
		*new = ft_strsub(*tmp, 0, i - 1);
		*new2 = ft_strsub(*tmp, i + 1, ft_strlen(*tmp) - (i + 1));
		ft_strdel(tmp);
		*tmp = ft_strjoin(*new, *new2);
		ft_strdel(new2);
	}
	ft_strdel(new);
	return (0);
}

static int		clear_quote(char **str, char *tmp)
{
	char		*new;
	char		*new2;
	int			i;

	if (!(tmp = ft_strdup(*str)))
		return (-1);
	new = NULL;
	new2 = NULL;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\"' || tmp[i] == '\'')
		{
			if (clear_quote_suite(&tmp, i, &new, &new2) == 1)
				return (1);
			i = 0;
		}
		else
			i++;
	}
	ft_strdel(str);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (0);
}

static int		delete_char_suite(char **str, int i)
{
	char	*prev;
	char	*new;

	prev = NULL;
	new = NULL;
	prev = ft_strsub(*str, 0, i);
	if (i == ft_strlen(*str) - 1)
		new = ft_strsub(*str, i, ft_strlen(*str) - (i));
	else
		new = ft_strsub(*str, i + 1, ft_strlen(*str) - (i + 1));
	ft_strdel(str);
	*str = ft_strjoin(prev, new);
	ft_strdel(&prev);
	ft_strdel(&new);
	return (0);
}

static int		delete_char(char **str, int i, int quote, int dquote)
{
	char		*tmp;

	tmp = ft_strdup(*str);
	while (i < ft_strlen(tmp))
	{
		if (tmp[i] == '\"' && dquote == 0)
			dquote = 1;
		else if (tmp[i] == '\"' && dquote == 1)
			dquote = 0;
		else if (tmp[i] == '\'' && quote == 0)
			quote = 1;
		else if (tmp[i] == '\'' && quote == 1)
			quote = 0;
		else if (tmp[i] == '\\' && tmp[i + 1] != '\\' && quote == 0 &&
	dquote == 0)
		{
			delete_char_suite(str, i);
			ft_strdel(&tmp);
			tmp = ft_strdup(*str);
			i = 0;
		}
		i++;
	}
	ft_strdel(&tmp);
	return (0);
}

char			**split_cmd(char *str, int i)
{
	char		**new;
	char		*tmp;

	delete_char(&str, 0, 0, 0);
	new = ft_strsplit(str, ' ');
	tmp = NULL;
	while (new[i])
	{
        if (clear_quote(&new[i], tmp) == 1)
		{
			ft_strdel(&str);
			i = 0;
		}
		else
			i++;
		ft_strdel(&tmp);
	}
	return (new);
}
