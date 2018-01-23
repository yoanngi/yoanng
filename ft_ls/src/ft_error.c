#include "ft_ls.h"

void	ft_error(s_struct *data)
{
	ft_putstr("ft_ls : illegal option -- ");
	ft_putstr(data->invalid);
	ft_putstr("\nusage: ls [-Rratl] [file...]\n");
}
