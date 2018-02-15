/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fonctionsup.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 13:35:05 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 13:54:14 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "client.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		((char*)s)[i] = 0;
		i++;
	}
}

int		ft_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
