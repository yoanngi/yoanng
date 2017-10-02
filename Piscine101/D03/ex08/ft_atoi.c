/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 09:50:52 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/10 20:00:55 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int nb;
	int bn;

	nb = 0;
	bn = 1;
	while ((*str == '\t') || (*str == '\n') || (*str == '\r') || (*str == '\v')
	|| (*str == '\f'))
		str++;
	if (*str == '-')
	{
		bn *= -1;
		str++;
	}
	if (*str == '+')
		str++;
	while ((*str >= 48) && (*str <= 57))
	{
		nb *= 10;
		nb += (*str - 48);
		str++;
	}
	return (nb * bn);
}
