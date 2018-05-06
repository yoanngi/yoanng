/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_minishell.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 13:35:53 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Print good prompt
*/

static void		ft_display(t_struct *data)
{
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

static int		ft_check_command(char **line, t_struct *data, int epur)
{
	int		exec;
	int		i;
	char	**tab;
	char	*tmp;

	exec = -1;
	i = 0;
	if ((ft_cmd_annexe(line, data)) == 0)
		return (0);
	tab = epur_tab(*line, epur);
	tmp = NULL;
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
	int		ret;

	ret = ft_search_enclosing(&line);
	if (ret == 1)
	{
		data->prompt_current = ft_strdup("subsh> ");
		data->charfound = ft_strdup(")");
		return (1);
	}
	if (ret == 2)
	{
		data->prompt_current = ft_strdup("cursh> ");
		data->charfound = ft_strdup("}");
		return (1);
	}
	if (ret == 3)
	{
		data->prompt_current = ft_strdup("quote> ");
		data->charfound = ft_strdup("\'");
		return (1);
	}
	if (ret == 4)
	{
		data->prompt_current = ft_strdup("dquote> ");
		data->charfound = ft_strdup("\"");
		return (1);
	}
	return (0);
}

/*
**	Minishell cmd_special
*/

static int		ft_minishell_spe(t_struct *data, char **line)
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

/*
**	Core Minishell
*/

int				ft_minishell(char **line, t_struct *data)
{
	int			cmd;
	int			quit;

	cmd = 0;
	quit = 0;
	while (quit == 0)
	{
		ft_display(data);
		get_next_line(0, line);
		signal(SIGINT, monsignal);
		if ((ft_strcmp("exit", *line)) == 0)
			quit = 1;
		if ((ft_strcmp("", *line)) != 0 && quit == 0)
		{
			if (cmd_special(*line, data) == 0)
			{
				cmd = ft_check_command(line, data, 0);
				ft_error(cmd, line);
			}
			else
				ft_minishell_spe(data, line);
		}
		ft_strdel(line);
	}
	return (0);
}
