/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cmd_annexe.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 11:20:03 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/15 11:38:54 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static char		**ft_initialise_builtins(void)
{
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char *) * 7)))
		return (NULL);
	tab[0] = ft_strdup("cd");
	tab[1] = ft_strdup("echo");
	tab[2] = ft_strdup("setenv");
	tab[3] = ft_strdup("unsetvenv");
	tab[4] = ft_strdup("env");
	tab[5] = ft_strdup("exit");
	tab[6] = NULL;
	return (tab);
}

int				ft_cmd_annexe(char **line, t_struct *data)
{
	char	**tab;
	char	**builtins;
	int		i;

	(void)data;
	i = 0;
	builtins = ft_initialise_builtins();
	tab = ft_strsplit(*line, ' ');
	while (builtins[i])
	{
		if (ft_strcmp(tab[0], builtins[i]) == 0)
		{
			printf("Commande found !\n");
			return (0);
		}
		i++;
	}
	ft_del_tab(tab);
	ft_del_tab(builtins);
	return (1);
}
