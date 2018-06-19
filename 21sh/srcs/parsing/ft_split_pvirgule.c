/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_pvirgule.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 14:38:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 14:20:46 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int		ft_split_pvir_suite(char **line, int i, t_ins **lst)
{
	char	*tmp;
	int		i2;

	i2 = i;
	tmp = ft_strdup(*line);
	(*lst)->str = ft_strsub(*line, 0, i);
	(*lst)->next = ft_init_ins();
	*lst = (*lst)->next;
	while (tmp[i2] == ';')
		i2++;
	ft_strdel(line);
	*line = ft_strsub(tmp, i2, ft_strlen(tmp) - i2);
	ft_strdel(&tmp);
	return (0);
}

t_ins			*ft_split_pvirgule(char *line, t_ins *lst)
{
	t_ins	*start;
	int		i;
	int		j;
	int		quote;

	i = 0;
	j = 0;
	quote = 0;
	start = lst;
	while (line[i])
	{
		if ((line[i] == '\'' || line[i] == '\"') && quote == 0)
			quote = 1;
		else if ((line[i] == '\'' || line[i] == '\"') && quote == 1)
			quote = 0;
		if (quote == 0 && line[i] == ';')
			i = ft_split_pvir_suite(&line, i, &lst);
		else
			i++;
	}
	lst->str = ft_strdup(line);
	return (start);
}
