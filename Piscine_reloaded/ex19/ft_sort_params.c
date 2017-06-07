/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yginet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 11:05:17 by yginet            #+#    #+#             */
/*   Updated: 2017/03/28 12:21:06 by yginet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] < s2[i])
		return (-1);
	else if (s1[i] == s2[i])
		return (0);
	else
	{
		return (1);
	}
}

int		array_pass(int len, char *array[])
{
	int		i;
	int		ok;
	char	*tmp;

	i = 0;
	ok = 1;
	while (++i < (len - 1))
	{
		if (ft_strcmp(array[i], array[i + 1]) > 0)
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			ok = 0;
		}
	}
	return (ok);
}

int		print_params(int argc, char *argv[])
{
	int	argn;

	argn = 0;
	while (++argn < argc)
	{
		while (*argv[argn] != '\0')
			ft_putchar(*(argv[argn]++));
		ft_putchar('\n');
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc < 2)
		return (0);
	if (argc > 2)
		while (!array_pass(argc, argv))
			continue;
	return (print_params(argc, argv));
}
