/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   good_tab_cmd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/08 15:29:39 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/08 16:47:24 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int			search_redirection(t_cmd **lst, char *str, int i)
{
	t_path		*new;
	int			j;

	new = NULL;
	j = i + 1;
	i++;
	while (str[i] && str[i] != '|' && str[i] != '<')
	{
		if (str[i] == '>')
		{
			if (new == NULL)
			{
				new = ft_init_path();
				(*lst)->pathname = new;
			}
			else if (new->name != NULL)
			{
				new->next = ft_init_path();
				new = new->next;
			}
			printf("str = %s || j = %d || i = %d\n", str, j, i);
			new->name= ft_strsub(str, j, i);
			clear_line(&new->name);
			printf("name = |%s|\n", new->name);
			j = i + 1;
		}
		i++;
	}
	if (new == NULL)
	{
		new = ft_init_path();
		(*lst)->pathname = new;
		new->name = ft_strsub(str, j, ft_strlen(str) - j);
		clear_line(&new->name);
		j = ft_strlen(str);
	}
	return (j);
}

int			good_tab_cmd(t_struct *data, t_cmd **lst, char *str, int i)
{
	char		*tmp;
	int			ret;
	int			start;

	tmp = NULL;
	ret = 0;
	start = 0;
	if (str == NULL)
		return (0);
	if (i == 0)
	{
		start = 1;
		while (str[i] && (str[i] != '|' || str[i] != '>'))
			i++;
	}
	if (i == ft_strlen(str) - 1)
		tmp = ft_strdup(str);
	else
		tmp = ft_strsub(str, start, i);
	insert_cmd_simple(data, lst, tmp);
	ret = ft_strlen(tmp);
	ft_strdel(&tmp);
	if ((*lst)->op_next == 2)
		ret = search_redirection(lst, str, i);
	else if ((*lst)->op_next == 3)
		ret = search_redirection(lst, str, i + 1);
	return (ret);
}
