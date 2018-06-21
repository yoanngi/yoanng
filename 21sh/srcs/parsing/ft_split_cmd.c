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

static int			ft_insert_cmd(t_cmd **new, t_struct *data, char **str, int i)
{
	char	*tmp;

    if ((*new)->op_redir == 2 || (*new)->op_redir == 3)
    {
        (*new)->pathname = ft_strdup(*str + 1);
        return (0);
    }
	if ((*new)->tab_cmd != NULL)
	{
		(*new)->next = ft_init_cmd();
		*new = (*new)->next;
	}
	tmp = ft_strsub(*str, 0, i);
	(*new)->tab_cmd = ft_strsplit(tmp, ' ');
	(*new)->rep = ft_search_path((*new)->tab_cmd[0], data);
    if ((*new)->rep ==  NULL)
        (*new)->pathname = ft_strdup((*new)->tab_cmd[0]);
	(*new)->env = ft_duplicate_tab(data->env);
    if (i == ft_strlen(*str))
        (*new)->op_next = 0;
    else
    	(*new)->op_next = ft_search_opnext(*str, i);
	ft_strdel(&tmp);
	return (0);

}

static int          ft_split_cmd_suite(t_cmd **new, t_struct *data, char **str)
{
    char    *tmp;
    char    *tmp2;
    int     i;

    tmp = ft_strdup(*str);
    tmp2 = NULL;
    i = 0;
    while (tmp[i])
    {
        if (tmp[i] == '|' || tmp[i] == '>')
        {
            ft_insert_cmd(new, data, &tmp, i);
            if (i < ft_strlen(tmp))
            {
                tmp2 = ft_strdup(tmp);
                if (tmp2[i] == '>')
                    (*new)->op_redir = 2;
                if (tmp2[i + 1] == '>')
                    (*new)->op_redir = 3;
                ft_strdel(&tmp);
                tmp = ft_strsub(tmp2, i + 1, ft_strlen(tmp2) - (i + 1));
                ft_strdel(&tmp2);
                i = 0;
            }
        }
        i++;
    }
    ft_insert_cmd(new, data, &tmp, i);
    ft_strdel(&tmp);
    return (0);
}

t_cmd				*ft_split_cmd(char *str, t_struct *data)
{
	t_cmd   *new;
	t_cmd   *start;
	int		i;

	i = 0;
    new = NULL;
    start = NULL;
	if (!(new = ft_init_cmd()))
		return (NULL);
	start = new;
    // A modifier, clear line ne vire pas tous les spaces inutiles
	clear_line(&str);
    // ***********************************************************
    if (ft_strstr(str, "|") != NULL || ft_strstr(str, ">") != NULL ||
    ft_strstr(str, "<") != NULL)
        ft_split_cmd_suite(&new, data, &str);
    else
		ft_insert_cmd(&new, data, &str, ft_strlen(str));
	return (start);
}
