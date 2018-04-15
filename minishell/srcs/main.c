/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/15 11:06:49 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Print infos in term
*/

static void		ft_display(void)
{
	ft_putstr("$> ");
	// Print User
}

/*
**	Add commande in end of path
*/

static char		*ft_add_line(char *str, char *add)
{
	char	*tmp;
	char	*new;

	tmp = ft_strjoin(str, "/");
	new = ft_strjoin(tmp, add);
	ft_strdel(&tmp);
	return (new);
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
		ft_display();
		get_next_line(0, &line);
		cmd = ft_check_command(&line, data);
		ft_error(cmd, &line);
		ft_strdel(&line);
	}
	ft_delete_struct(data);
	return (0);
}
