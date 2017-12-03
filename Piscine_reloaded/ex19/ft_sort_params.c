/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:08:46 by yoginet           #+#    #+#             */
/*   Updated: 2017/11/10 10:25:37 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_swap(char **tab, int i)
{
	char *tmp;

	tmp = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = tmp;
}

void	ft_sort_params(int i, int argc, char **argv)
{
	int j;
	int compt;

	j = argc;
	compt = 0;
	while (i < argc - 1)
	{
		if (argv[i][compt] > argv[i + 1][compt])
		{
			ft_swap(argv, i);
			i = 1;
		}
		if (argv[i][compt] == argv[i + 1][compt])
			compt++;
		if (argv[i][compt] < argv[i + 1][compt])
		{
			compt = 0;
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	ft_sort_params(i, argc, argv);
	while (i != argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
