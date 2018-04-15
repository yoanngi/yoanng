/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 15:32:31 by yoginet     ###    #+. /#+    ###.fr     */
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

	exec = 0;
	i = 0;
	tab = ft_strsplit(*line, ' ');
	tmp = NULL;
	while (data->tab_path[i])
	{
	//	printf("Valeur de execve = %d || tab_path[%d] = %s\n", exec, i, data->tab_path[i]);
		tmp = ft_add_line(data->tab_path[i], *line);
		exec = ft_process(tmp, tab);
		ft_strdel(&tmp);
		i++;
	}
	ft_del_tab(tab);
	return (0);
}

/*
**	Core Minishell
*/
int				main(int argc, char **argv, char **env)
{
	char		*line;
	t_struct	*data;

	(void)argc;
	(void)argv;
	line = NULL;
	data = ft_my_struct(env);
	while (1)
	{
		ft_display();
		get_next_line(0, &line);
		ft_check_command(&line, data);
		ft_strdel(&line);
	}
	ft_delete_struct(data);
	return (0);
}
