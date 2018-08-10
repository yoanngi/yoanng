/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_cmd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:08:13 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/10 15:05:45 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int			good_op_next(t_cmd **new, char *str, int i)
{
	if (i >= ft_strlen(str))
		return (1);
	if (str[i] == '|' && (str[i + 1] != '|' && str[i + 1] != '\0'))
		(*new)->op_next = 1;
	else if (str[i] == '>' && str[i + 1] != '>')
		(*new)->op_next = 2;
	else if (str[i] == '>' && str[i + 1] == '>')
		(*new)->op_next = 3;
	else if (str[i] == '<' && str[i + 1] != '<')
		(*new)->op_next = 4;
	else if (str[i] == '<' && str[i + 1] == '<')
		(*new)->op_next = 5;
	else if (str[i] == '&' && str[i + 1] != '&')
		(*new)->op_next = 6;
	else if (str[i] == '&' && str[i + 1] == '&')
		(*new)->op_next = 7;
	else if (str[i] == '|' && str[i + 1] == '|')
		(*new)->op_next = 8;
	else if (str[i] == '>' && str[i + 1] == '&')
		ft_redirection_avancees(new, str, i);
	return (0);
}

static int			ft_split_cmd_suite(t_cmd **new, t_struct *data, char *str,
	int i)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strstr(str, ">") == NULL && ft_strstr(str, "|") == NULL)
		insert_cmd_simple(data, new, str);
	else
	{
		tmp = ft_strdup(str);
		while (tmp[i])
		{
			if (tmp[i] == '|' || tmp[i] == '>' || i == ft_strlen(tmp) - 1)
			{
				good_op_next(new, tmp, i);
				i = good_tab_cmd(data, new, tmp, i);
				i = resize_str(&tmp, i + 1) - 1;
				if (tmp == NULL)
					return (0);
				(*new)->next = ft_init_cmd();
				*new = (*new)->next;
			}
			i++;
		}
		ft_strdel(&tmp);
	}
	return (0);
}

t_cmd				*ft_split_cmd(char *str, t_struct *data)
{
	t_cmd	*new;
	t_cmd	*start;
	int		i;

	i = 0;
	new = NULL;
	start = NULL;
	if (!(new = ft_init_cmd()) || str == NULL)
		return (NULL);
	start = new;
	clear_line(&str);
	if (str == NULL)
	{
		new = clear_cmd(new);
		return (NULL);
	}
	replace_in_line(data, &str);
	if (ft_split_cmd_suite(&new, data, str, 0) == 1)
	{
		new = clear_cmd(new);
		return (NULL);
	}
	return (start);
}
