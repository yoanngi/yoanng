/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:06:21 by yoginet           #+#    #+#             */
/*   Updated: 2017/11/10 10:20:23 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char	a;
	int		i;

	a = '0';
	i = 0;
	while (i < 10)
	{
		ft_putchar(a);
		a++;
		i++;
	}
}
