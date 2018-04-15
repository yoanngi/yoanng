/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_echo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/15 13:51:31 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		func_echo(char **line, t_struct *data)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(*line, ' ');
	ft_strdel(&tab[0]);
	while (data->tab_path[i])
	{
		tab[0] = ft_add_line(data->tab_path[i], "echo");
		if ((ft_process(tab[0], tab)) > -1)
		{
			ft_strdel(&tab[0]);
			ft_del_tab(tab);
			return (0);
		}
		ft_strdel(&tab[0]);
		i++;
	}
	ft_error(1, line);
	return (1);
}
