/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_cmd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:08:13 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/08 16:50:52 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
static int		check_arg_line(t_cmd **new, char **str)
{
	t_path		*lst;

	lst = NULL;
	printf("%s || str = |%s|\n", __func__, *str);
	if (*str == NULL)
		return (0);
	if (ft_strstr(*str, "|") == NULL && ft_strstr(*str, ">") == NULL)
	{
		if (ft_strstr(*str, "-") == NULL && (*new)->pathname != NULL)
		{
			lst = (*new)->pathname;
			while (lst->next)
				lst = lst->next;
			lst->next = ft_init_path();
			lst = lst->next;
			lst->name = ft_strdup(*str);
			clear_line(&lst->name);
			ft_strdel(str);
		}
		else
			printf("DEBUG : option a rajouter dans tab_cmd\n");
	}
	return (0);
}
*/

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

static int			ft_split_cmd_suite(t_cmd **new, t_struct *data, char *str)
{
	int		i;

	i = 0;
	if (ft_strstr(str, ">") == NULL && ft_strstr(str, "|") == NULL)
		insert_cmd_simple(data, new, str);
	else
	{
		while (str[i])
		{
			if (str[i] == '|' || str[i] == '>' || i == ft_strlen(str) - 1)
			{
				good_op_next(new, str, i);
				i = good_tab_cmd(data, new, str, i);
				i = resize_str(&str, i + 1) - 1;
				if (str == NULL)
					return (0);
				(*new)->next = ft_init_cmd();
				*new = (*new)->next;
			}
			i++;
		}
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
	if (!(new = ft_init_cmd()))
		return (NULL);
	start = new;
	clear_line(&str);
	if (str == NULL)
	{
		new = clear_cmd(new);
		return (NULL);
	}
	replace_in_line(data, &str);
	if (ft_split_cmd_suite(&new, data, str) == 1)
	{
		new = clear_cmd(new);
		return (NULL);
	}
	return (start);
}
