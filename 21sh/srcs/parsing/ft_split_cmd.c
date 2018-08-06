/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_cmd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:08:13 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/06 16:51:03 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static t_path		*search_redirection(char *str, int i)
{
	t_path		*new;
	int			j;

    printf("START %s\n", __func__);
	new = NULL;
	j = i;
	new = ft_init_path();
	while (str[i])
	{
		if (str[i + 1] == '\0' || str[i] == '>')
		{
			printf("new->name = %s\n", new->name);
			if (new->name != NULL)
			{
				new->next = ft_init_path();
				new = new->next;
			}
			if (str[i + 1] == '\0')
				new->name = ft_strsub(str, j, i + 1);
			else
				new->name = ft_strsub(str, j, i);
			printf("new->name = %s\n", new->name);
			j = i;
		}
		i++;
	}
	resize_str(&str, j, i);
    printf("END %s\n", __func__);
	return (new);
}

static int			good_tab_cmd(t_struct *data, t_cmd **new, char *str, int i)
{
	char		*tmp;

	tmp = NULL;
	if (str == NULL)
		return (1);
	tmp = ft_strsub(str, 0, i);
	printf("TMP = |%s|\n", tmp);
	(*new)->tab_cmd = split_cmd(tmp, 0);
	chose_rep(data, new, 0);
	(*new)->env = ft_duplicate_tab(data->env);
	ft_strdel(&tmp);
	if ((*new)->op_next == 2 || (*new)->op_next == 3)
		(*new)->pathname = search_redirection(str, i);
	printf("last resize\n");
	if (resize_str(&str, 0, i) == 1)
		return (-1);
	return (0);
}

static int			good_op_next(t_struct *data, t_cmd **new, char *str, int i)
{
	if ((i + 1) >= ft_strlen(str))
		return (1);
	if (str[i] == '|' && str[i + 1] != '|')
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
	if (good_tab_cmd(data, new, str, i) != 0)
		return (1);
	return (0);
}

int				resize_str(char **str, int start, int end)
{
	char	*tmp;

	tmp = NULL;
	if (*str == NULL)
		return (1);
	if (!(tmp = ft_strsub(*str, start, end)))
		return (1);
	printf("TMP = %s\n", tmp);
	ft_strdel(str);
	if (!(*str = ft_strdup(tmp)))
		return (1);
	ft_strdel(&tmp);
	if (ft_strlen(*str) <= 1)
		ft_strdel(str);
	return (0);
}

static int		ft_split_cmd_suite(t_cmd **new, t_struct *data, char *str)
{
	int		i;

	i = 0;
    printf("START %s\n", __func__);
	while (str[i])
	{
		if (str[i] == '|' || str[i] == '>')
		{
			if (good_op_next(data, new, str, i) != 0)
				return (1);
			if (str == NULL)
				return (0);
			(*new)->next = ft_init_cmd();
			*new = (*new)->next;
			i = 0;
		}
		i++;
	}
	if (good_tab_cmd(data, new, str, ft_strlen(str)) == 1)
		return (1);
    printf("END %s\n", __func__);
	return (0);
}

t_cmd			*ft_split_cmd(char *str, t_struct *data)
{
	t_cmd	*new;
	t_cmd	*start;
	int		i;

	i = 0;
	new = NULL;
	start = NULL;
    printf("START PARSING >>> %s\n", __func__);
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
    printf("END PARSING >>> %s\n\n", __func__);
	return (start);
}
