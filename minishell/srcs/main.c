/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 10:54:53 by yoginet     ###    #+. /#+    ###.fr     */
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
	ft_putstr("\033[32m $> \033[0m");
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
**	Core Minishell
*/

int				main(int argc, char **argv, char **env)
{
	char		*line;
	t_struct	*data;
	int			cmd;

	(void)argc;
	(void)argv;
	line = NULL;
	data = ft_my_struct(env);
	cmd = 0;
	while (1)
	{
		ft_display(data);
		get_next_line(0, &line);
		if ((ft_strcmp("", line)) != 0)
		{
			cmd = ft_check_command(&line, data);
			ft_error(cmd, &line);
		}
		ft_strdel(&line);
	}
	ft_delete_struct(data);
	return (0);
}
