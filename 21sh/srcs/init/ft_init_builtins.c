/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_builtins.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 13:57:08 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 13:57:10 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	initialise commande sup in struct
*/

char		**ft_initialise_builtins(void)
{
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char *) * 6)))
		return (NULL);
	tab[0] = ft_strdup("cd");
	tab[1] = ft_strdup("echo");
	tab[2] = ft_strdup("setenv");
	tab[3] = ft_strdup("unsetenv");
	tab[4] = ft_strdup("env");
	tab[5] = NULL;
	return (tab);
}
