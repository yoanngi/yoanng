/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_cmd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:08:13 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 16:47:34 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int			ft_search_opnext(char *str, int i)
{
	int		len;

	len = ft_strlen(str);
	if (i < len)
	{
		if (str[i] == '<' && str[i + 1] == '<')
			return (5);
		if (str[i] == '>' && str[i + 1] == '>')
			return (3);
	}
	if (str[i] == '|')
		return (1);
	else if (str[i] == '>')
		return (2);
	else if (str[i] == '<')
		return (4);
	else if (str[i] == '&')
		return (4);
	return (0);
}

/*
**	Ajout des builtins a faire
*/

int					ft_split_cmd_suite(t_cmd **new, t_struct *data, char **str, int i)
{
	char	*tmp;

	if ((*new)->tab_cmd != NULL)
	{
		(*new)->next = ft_init_cmd();
		*new = (*new)->next;
	}
	tmp = ft_strsub(*str, 0, i);
	(*new)->tab_cmd = ft_strsplit(tmp, ' ');
	(*new)->rep = ft_search_path((*new)->tab_cmd[0], data);
	(*new)->env = ft_duplicate_tab(data->env);
	(*new)->op_next = ft_search_opnext(*str, i);
	ft_strdel(&tmp);
	tmp = ft_strdup(*str);
	ft_strdel(str);
	if (i == ft_strlen(tmp))
		*str = NULL;
	else
		*str = ft_strdup(tmp + (i + 1));
	ft_strdel(&tmp);
	return (0);

}

// A modif

t_cmd				*ft_split_cmd(char *str, t_struct *data)
{
	t_cmd   *new;
	t_cmd   *start;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (!(new = ft_init_cmd()))
		return (NULL);
	start = new;
	clear_line(&str);
	while (str[i])
	{
		if (str[i] == '|' || str[i] == '<' || str[i] == '>')
		{
			x++;
			i = ft_split_cmd_suite(&new, data, &str, i);
		}
		else
			i++;
	}
	if (x == 0)
		ft_split_cmd_suite(&new, data, &str, ft_strlen(str));
	return (start);
}
