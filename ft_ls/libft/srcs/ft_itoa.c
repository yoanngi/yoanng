/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:07:50 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 10:08:03 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_neg_ornot(int *n)
{
	int i;

	if (*n < 0)
	{
		i = 1;
		*n *= -1;
	}
	else
		i = 0;
	return (i);
}

static char			ft_itoa_insert(char *tab, int len, int nb, int neg)
{
	while (len--)
	{
		tab[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (neg == 1)
		tab[0] = '-';
	return (*tab);
}

char				*ft_itoa(int n)
{
	char		*new;
	size_t		i;
	int			tmp;
	int			neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 2;
	tmp = n;
	neg = ft_neg_ornot(&n);
	while (tmp /= 10)
		i++;
	i = i + neg;
	if ((new = (char *)malloc(sizeof(char) * i)) == NULL)
		return (NULL);
	i--;
	new[i] = '\0';
	ft_itoa_insert(new, i, n, neg);
	return (new);
}
