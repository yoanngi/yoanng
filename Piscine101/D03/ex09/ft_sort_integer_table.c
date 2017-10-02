/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 20:06:22 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/13 09:52:04 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int		i;
	int		count;
	int		tmp;

	i = 0;
	count = i + 1;
	while (i < size - 1)
	{
		if (tab[i] > tab[count])
		{
			tmp = tab[i];
			tab[i] = tab[count];
			tab[count] = tmp;
			i = 0;
			count = i + 1;
		}
		else
		{
			i++;
			count = i + 1;
		}
	}
}
