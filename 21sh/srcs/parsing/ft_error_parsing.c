/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error_parsing.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 10:26:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/10 16:36:56 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Check les cas d'erreur (line non spliter)
**	Check surtout debut de line et fin de line
*/

static void		print_msg_error(char *str, int i)
{
	ft_putstr_fd("21sh: ", 2);
	if (i == 1)
		ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
	else if (i == 2)
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\"\n", 2);
	}
	else if (i == 3)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
	}
}

static int		ft_check_start_line(char *str)
{
	if ((str[0] == '>' || str[0] == '<') && (str[1] != '>' || str[1] != '<'))
	{
		print_msg_error(str, 1);
		return (1);
	}
	else if (str[0] == '|' || str[0] == '&' || str[0] == ';' || str[0] == '!')
	{
		print_msg_error(str, 2);
		return (1);
	}
	return (0);
}

static int		check_end_line(char *line)
{
	int		len;

	len = ft_strlen(line);
	if (line[len - 1] == '>' || line[len - 1] == '<' || line[len - 1] == '|')
	{
		print_msg_error(line + (len - 1), 2);
		return (1);
	}
	return (0);
}

static int		check_str(char *str, int i)
{
	int		len;

	len = ft_strlen(str);
	if (i + 1 >= len)
		return (0);
	if (str[i] == '>' && str[i + 1] == '<')
	{
		print_msg_error("<", 2);
		return (1);
	}
	if (str[i] == ';' && str[i + 1] == ';')
	{
		print_msg_error(";;", 2);
		return (1);
	}
	if (str[i] == '!')
	{
		print_msg_error(NULL, 1);
		return (1);
	}
	return (0);
}

static int		check_regex_invalid(char *str, int i)
{
	int		quote;
	int		dquote;

	quote = 0;
	dquote = 0;
	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (str[i] == '\'' && quote == 0)
			quote = 1;
		else if (str[i] == '\'' && quote == 1)
			quote = 0;
		else if  (str[i] == '\"' && dquote == 0)
			dquote = 1;
		else if (str[i] == '\"' && dquote == 1)
			dquote = 0;
		if (quote == 0 && dquote == 0)
		{
			if (check_str(str, i) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int				ft_nefaitrien(char **line)
{
	if (ft_check_start_line(*line) == 1)
		return (1);
	else if (ft_strstr(*line, "\"") == NULL &&
	(ft_strstr(*line, ";;") || ft_strstr(*line, "><")))
	{
		print_msg_error(*line, 2);
		return (1);
	}
	else if (check_end_line(*line) == 1)
		return (1);
	else if (check_regex_invalid(*line, 0) == 1)
		return (1);
	return (0);
}
