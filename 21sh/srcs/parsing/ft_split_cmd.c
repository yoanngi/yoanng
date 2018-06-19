/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_cmd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:08:13 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 16:23:22 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static char			*ft_search_path(char *str, t_struct *data)
{
	(void)str;
	(void)data;
	return (ft_strdup("/bin/ls"));
}

static int			ft_search_signe(char *str, int i)
{
	if (str[i] == '\0')
		return (0);
	else if (str[i] == '|')
		return (1);
	else if (str[i] == '>')
	{
		if (i < ft_strlen(str))
		{
			if (str[i + 1] == '>')
				return (3);
		}
		return (2);
	}
	return (-1);
}

static int			ft_search_opnext(char *str)
{
	int		i;
	int		quote;
	int		dquote;
	int		ret;

	i = 0;
	quote = 0;
	dquote = 0;
	ret = -1;
	while (str[i])
	{
		if ((str[i] == '\'') && quote == 0)
			quote = 1;
		if ((str[i] == '\'') && quote == 1)
			quote = 0;
		if ((str[i] == '\"') && dquote == 0)
			dquote = 1;
		if ((str[i] == '\"') && dquote == 1)
			dquote = 0;
		if (quote == 0 && dquote == 0)
			ret = ft_search_signe(str, i);
		if (ret >= 0)
			return (ret);
		i++;
	}
	return (0);
}

t_cmd				*ft_split_cmd(char *str, t_struct *data)
{
	t_cmd   *new;

	if (!(new = ft_init_cmd()))
		return (NULL);
	clear_line(&str);
	// add builtins //
	new->tab_cmd = ft_strsplit(str, ' ');
	new->rep = ft_search_path(new->tab_cmd[0], data);
	new->env = ft_duplicate_tab(data->env);
	new->op_next = ft_search_opnext(str);
	return (new);
}
