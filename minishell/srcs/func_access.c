#include "minishell.h"

/*
**	Check access or not (cmd cd)
*/

int		ft_access(char *path)
{
	if (access(path, F_OK))
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file of directory\n", 2);
		return (-1);
	}
	if (access(path, R_OK))
	{
		ft_putstr_fd("cd: permission denied: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (-1);
	}
	return (0);
}
