/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error_parsing.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 10:26:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 10:45:18 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	check_pvir_suite(char *str, int i)
{
	int		len;

	len = ft_strlen(str);
	if (len == i)
		return (0);
	if (str[i] != ';')
		return (0);
	if (str[i] == ';' && str[i + 1] == ';')
		return (1);
	return (0);
}

int			ft_check_pvir_error(char *str)
{
	int		i;
	int		quote;
	int		dquote;

	i = 0;
	quote = 0;
	dquote = 0;
	while (str[i])
	{
		if (str[i] == '\'' && quote == 0)
			quote = 1;
		else if (str[i] == '\'' && quote == 1)
			quote = 0;
		else if (str[i] == '\"' && dquote == 0)
			dquote = 1;
		else if (str[i] == '\"' && dquote == 1)
			dquote = 0;
		else if (quote == 0 && dquote == 0)
		{
			if (check_pvir_suite(str, i) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int			ft_nefaitrien(char **line)
{
	if (ft_strlen(*line) == 0 || (ft_strlen(*line) == 1 && *line[0] == ';'))
	{
		ft_strdel(line);
		return (1);
	}
	else if (ft_strstr(*line, ";;") != NULL)
	{
		if (ft_check_pvir_error(*line) == 1)
		{
			ft_putstr_fd("21sh: parse error near `;;'\n", 2);
			ft_strdel(line);
			return (1);
		}
	}
	return (0);
}
