#include "minishell.h"

void		basic_error(char *name)
{
	ft_putstr_fd("Error :", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
}
