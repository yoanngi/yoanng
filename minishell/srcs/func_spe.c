/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_spe.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/21 09:57:38 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 10:01:49 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	func_bracket : check ( && {
*/

static int			func_bracket(char **line, char **line_2, t_struct *data)
{
	(void)line;
	(void)line_2;
	(void)data;
	return (0);
}

static void			ft_clean_string(char **str, t_struct *data)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(*str);
	ft_strdel(str);
	while (tmp[i])
	{
		if (tmp[i] == data->charfound[0])
		{
			*str = ft_strsub(tmp, 0, i);
			ft_strdel(&tmp);
			return ;
		}
		i++;
	}
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

/*
**	func_spe : check ' && "
**	39 = '
**	34 = "
*/

int					func_spe(char **line, char **line_2, t_struct *data)
{
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	ft_clean_string(line_2, data);
	if (*line[0] == 34 || *line[0] == 39)
	{
		str = ft_strdup("\\n");
		tmp = ft_strdup(*line);
		ft_strdel(line);
		*line = ft_strjoin(tmp, str);
		ft_strdel(&tmp);
		tmp = ft_strjoin(*line, *line_2);
		ft_strdel(line);
		ft_strdel(&str);
		*line = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else
		func_bracket(line, line_2, data);
	return (0);
}
