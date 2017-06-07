/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yginet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:58:47 by yginet            #+#    #+#             */
/*   Updated: 2017/03/28 11:02:16 by yginet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;
	int index;

	i = 1;
	index = 0;
	while (argc > 1)
	{
		while (argv[i][index])
		{
			ft_putchar(argv[i][index]);
			index++;
		}
		index = 0;
		ft_putchar('\n');
		i++;
	}
	return (0);
}
