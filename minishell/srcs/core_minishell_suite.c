/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_minishell_suite.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 09:21:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 09:21:17 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Minishell spe
**	For change prompt (quote, dquote, ....)
*/

int			ft_minishell_spe(t_struct *data, char **line)
{
	char	*line_2;
	int		quit;
	int		ret;

	line_2 = NULL;
	quit = 0;
	ret = 0;
	while (quit == 0)
	{
		ft_display(data);
		get_next_line(0, &line_2);
		if (ft_strstr(line_2, data->charfound))
			quit = 1;
		func_spe(line, &line_2, data);
		ft_strdel(&line_2);
	}
	ret = ft_check_command(line, data, 0);
	ft_error(ret, line);
	ft_strdel(&data->prompt_current);
	ft_strdel(&data->charfound);
	ft_strdel(&line_2);
	return (ret);
}
