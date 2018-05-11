/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_enclosing.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/21 11:13:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 13:02:40 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Search if open a new term in term
*/

int			ft_search_enclosing(char **str)
{
	(void)str;
	return (0);
}

/*
**	Special command
*/

int			cmd_special(char *line, t_struct *data, int ret)
{
	ret = ft_search_enclosing(&line);
	if (ret == 1)
	{
		data->prompt_current = ft_strdup("subsh> ");
		data->charfound = ft_strdup(")");
	}
	else if (ret == 2)
	{
		data->prompt_current = ft_strdup("cursh> ");
		data->charfound = ft_strdup("}");
	}
	else if (ret == 3)
	{
		data->prompt_current = ft_strdup("quote> ");
		data->charfound = ft_strdup("\'");
	}
	else if (ret == 4)
	{
		data->prompt_current = ft_strdup("dquote> ");
		data->charfound = ft_strdup("\"");
	}
	if (data->charfound != NULL)
		return (1);
	return (0);
}
