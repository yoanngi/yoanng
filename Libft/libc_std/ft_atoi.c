#include "libft.h"

int		ft_atoi(const char *str)
{
	int nb;
	int bn;

	nb = 0;
	bn = 1;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' || *str == ' ' || *str == '\f')
		str++;
	if (*str == '-')
	{
		bn = -1;
		str++;
	}
  	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		nb *= 10;
		nb += (*str - 48);
		str++;
	}
	return (nb * bn);
}
