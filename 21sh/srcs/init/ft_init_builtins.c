/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_builtins.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 13:00:14 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 13:34:44 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
**	initialise builtins in struct
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
