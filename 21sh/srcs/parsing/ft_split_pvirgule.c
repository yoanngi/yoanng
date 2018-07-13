/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_pvirgule.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 14:38:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 11:34:53 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int		verif_str(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 1)
		return (1);
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 1)
			return (0);
		i++;
	}
	return (1);
}

static int		ft_check_vir(t_ins **lst, char *line)
{
	if (ft_strstr(line, ";") == NULL)
	{
		(*lst)->str = ft_strdup(line);
		return (0);
	}
	return (1);
}

static int		ft_split_pvir_suite(char **line, int i, t_ins **lst)
{
	char	*tmp;

	tmp = NULL;
	if ((*lst)->str != NULL)
	{
		(*lst)->next = ft_init_ins();
		*lst = (*lst)->next;
	}
	if (i == ft_strlen(*line))
	{
		if (verif_str(*line) == 0)
			(*lst)->str = ft_strdup(*line);
		return (-2);
	}
	(*lst)->str = ft_strsub(*line, 0, i);
	tmp = ft_strsub(*line, i + 1, ft_strlen(*line) - (i + 1));
	if (ft_strstr(tmp, ";") == NULL && verif_str(tmp) == 0)
	{
		(*lst)->next = ft_init_ins();
		*lst = (*lst)->next;
		(*lst)->str = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (-2);
	}
	ft_strdel(&tmp);
	return (i);
}

static int		resize_line(char **str, int i, t_ins *lst)
{
	char	*tmp;
	int		len;

	tmp = NULL;
	if (lst->str == NULL)
		return (i);
	len = ft_strlen(lst->str);
	if (i == -2)
		return (-2);
	tmp = ft_strdup(*str);
	ft_strdel(str);
	*str = ft_strsub(tmp, len, ft_strlen(tmp) - len);
	ft_strdel(&tmp);
	return (-1);
}

t_ins			*ft_split_pvirgule(char *line, t_ins *lst)
{
	t_ins	*start;
	int		i;
	int		quote;
	char	*tmp;

	i = 0;
	quote = 0;
	tmp = NULL;
	start = lst;
	if (ft_check_vir(&lst, line) == 0)
		return (start);
	tmp = ft_strdup(line);
	while (i != -1)
	{
		if ((tmp[i] == '\'' || tmp[i] == '\"') && quote == 0)
			quote = 1;
		else if ((tmp[i] == '\'' || tmp[i] == '\"') && quote == 1)
			quote = 0;
		if ((quote == 0 && tmp[i] == ';') || i == ft_strlen(tmp))
			i = ft_split_pvir_suite(&tmp, i, &lst);
		i = resize_line(&tmp, i, lst);
		i++;
	}
	ft_strdel(&tmp);
	return (start);
}
