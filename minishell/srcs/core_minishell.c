/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_minishell.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 10:02:24 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Print prompt
**	User or path in bonus
*/

static void		ft_display(t_struct *data)
{
	(void)data;
	ft_putstr("\033[32m");
	if (data->prompt_current == NULL)
		ft_putstr(data->prompt);
	else
		ft_putstr(data->prompt_current);
	ft_putstr("\033[0m");
}

/*
**	Check commande and execute
*/

static int		ft_check_command(char **line, t_struct *data)
{
	int		exec;
	int		i;
	char	**tab;
	char	*tmp;

	exec = -1;
	i = 0;
	tab = ft_strsplit(*line, ' ');
	tmp = NULL;
	if ((ft_cmd_annexe(line, data)) == 0)
		return (0);
	while (data->tab_path[i])
	{
		tmp = ft_add_line(data->tab_path[i], tab[0]);
		if ((exec = ft_process(tmp, tab)) > -1)
		{
			ft_strdel(&tmp);
			ft_del_tab(tab);
			return (0);
		}
		ft_strdel(&tmp);
		i++;
	}
	ft_del_tab(tab);
	return (1);
}

/*
**	Special command
*/

static int		cmd_special(char *line, t_struct *data)
{
	if (ft_search_cd(line, '(', ')') == 1)
	{
		data->prompt_current = ft_strdup("subsh> ");
		data->charfound = ft_strdup(")");
		return (1);
	}
	if (ft_search_cd(line,'{', '}') == 1)
	{
		data->prompt_current = ft_strdup("cursh> ");
		data->charfound = ft_strdup("}");
		return (1);
	}
	if (ft_search_cd(line, 39, 39) == 1)
	{
		data->prompt_current = ft_strdup("quote> ");
		data->charfound = ft_strdup("'");
		return (1);
	}
	if (ft_search_cd(line, '"', '"') == 1)
	{
		data->prompt_current = ft_strdup("dquote> ");
		data->charfound = ft_strdup("\"");
		return (1);
	}
	return (0);
}

static int		ft_minishell_spe(t_struct *data, char **line)
{
	char	 *line_2;
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
	// add parse string for delete ' "
	ret = ft_check_command(line, data);
	ft_error(ret, line);
	ft_strdel(&data->prompt_current);
	ft_strdel(&data->charfound);
	return (ret);
}

/*
**	Core Minishell
*/

int				ft_minishell(char **line, t_struct *data)
{
	int			cmd;

	cmd = 0;
	while (1)
	{
		ft_display(data);
		get_next_line(0, line);
		if ((ft_strcmp("", *line)) != 0)
		{
			if (cmd_special(*line, data) == 0)
			{
				cmd = ft_check_command(line, data);
				ft_error(cmd, line);
			}
			else
				ft_minishell_spe(data, line);
		}
		ft_strdel(line);
	}
	return (0);
}
