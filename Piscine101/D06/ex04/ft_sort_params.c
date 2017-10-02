/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 09:42:02 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/19 20:51:24 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_swap(char **tab, int i, int count)
{
	char *tmp;

	tmp = tab[i];
	tab[i] = tab[count];
	tab[count] = tmp;
}

void	ft_sort_params(int size, char **tab)
{
	int		i;
	int		count;
	int		y;

	i = 1;
	y = 0;
	count = i + 1;
	while (i < size - 1)
	{
		if (tab[i][y] > tab[count][y])
		{
			ft_swap(tab, i, count);
			i = 1;
			count = i + 1;
		}
		else if (tab[i][y] == tab[count][y])
			y++;
		else if (tab[i][y] < tab[count][y])
		{
			i++;
			count = i + 1;
			y = 0;
		}
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	ft_sort_params(argc, argv);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
