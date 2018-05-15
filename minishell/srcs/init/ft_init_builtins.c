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