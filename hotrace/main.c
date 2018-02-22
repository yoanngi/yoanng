#include "hotrace.h"

int		main(void)
{
	if (ft_recupere_infos() == 0)
	{
		ft_putstr("Usage : ./hotrace\n");
		ft_putstr("Element a rechercher : [Enter your elements]\n");
		ft_putstr("Dans quoi rechercher : [Enter your elements]\n");
	}
	return (0);
}
