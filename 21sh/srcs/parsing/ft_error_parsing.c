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

/*
**  Ecrit le message d'erreur
*/

static int  error_enter(char *str, int i)
{
	ft_putstr_fd("21sh: syntax error near unexpected token ‘", 2);
    if (i == 1)
    {
        ft_putchar_fd(str[0], 2);
        ft_putchar_fd(str[0], 2);
    }
    else if (i == 2)
    {
        ft_putchar_fd(str[0], 2);
    }
	ft_putstr_fd("'\n", 2);
    return (0);
}

static int  verif_hard_suite(char *str, int i)
{
    int     len;

    len = ft_strlen(str);
    if (i < len - 1)
    {
        if (str[i] == ';' && str[i + 1] == ';')
            return (1);
    }
    return (0);
}

static int  verif_hard(char *str)
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
			if (verif_hard_suite(str, i) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int			ft_nefaitrien(char **line)
{
    if (ft_strlen(*line) == 0)
        return (1);
    if (ft_strstr(*line, "\"") || ft_strstr(*line, "\'"))
    {
       if (verif_hard(*line) == 1)
       {
           error_enter(*line, 2);
           return (1);
       }
    }
    else
    {
        if ((*line[0] == ';' || *line[0] == '|') || (ft_strstr(*line, ";;")))
        {
            error_enter(*line, 2);
            return (1);
        }
    }
	return (0);
}
