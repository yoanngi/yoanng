/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:05:06 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 10:05:13 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long int	nb;
	int				bn;

	nb = 0;
	bn = 1;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' ||
			*str == ' ' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			bn = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nb *= 10;
		nb += (*str - 48);
		str++;
	}
	return (((long long int)nb) * bn);
}
