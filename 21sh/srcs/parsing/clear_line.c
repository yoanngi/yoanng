/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clear_line.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/26 14:57:37 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 14:12:11 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**  Delete space and tab
**	9 = \t
*/

static void	ft_del_char(char **str, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strsub(*str, 0, i);
	tmp2 = ft_strsub(*str, i + 1, ft_strlen(*str) - (i - 1));
	ft_strdel(str);
	*str = ft_strjoin(tmp, tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}

static int	ft_clean_suite2(char *str, int i, int repere)
{
	if (str[i] == ' ' && repere == 0 && (str[i + 1] == ' ' ||
	str[i + 1] == 9))
		return (1);
	else if (str[i] == 9 && repere == 0 && (str[i + 1] == ' ' ||
	str[i + 1] == 9))
		return (1);
	return (0);
}

static int	ft_repere(char *str, int i, int repere)
{
	if ((str[i] == '\'' || str[i] == '\"') && repere == 0)
		return (1);
	else if ((str[i] == '\'' || str[i] == '\"') && repere == 1)
		return (0);
	return (repere);
}

static void	ft_clean_suite(char **line, int i, int repere)
{
	size_t	len;
	char	*str;

	str = ft_strdup(*line);
	len = ft_strlen(str);
	while (i < (int)len)
	{
		len = ft_strlen(str);
		repere = ft_repere(str, i, repere);
		if (i > 0 && repere == 0)
		{
			if (str[i] == '\t' && (str[i - 1] != ' ' || str[i - 1] != '\t') &&
	(str[i + 1] != ' ' || str[i + 1] != '\t'))
				str[i] = ' ';
		}
		else if (ft_clean_suite2(str, i, repere) == 1)
		{
			ft_del_char(&str, i);
			i = 0;
		}
		i++;
	}
	ft_strdel(line);
	*line = ft_strdup(str);
	ft_strdel(&str);
}

int			clear_line(char **line)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	str = ft_strdup(*line);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (i == ft_strlen(*line))
	{
		ft_strdel(line);
		return (0);
	}
	ft_strdel(line);
	*line = ft_strdup(str + i);
	ft_strdel(&str);
	ft_clean_suite(line, 0, 0);
	return (0);
}
