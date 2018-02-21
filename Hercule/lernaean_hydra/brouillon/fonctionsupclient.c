/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fonctionsupclient.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 14:29:48 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 15:13:58 by yoginet     ###    #+. /#+    ###.fr     */
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
		((char*)s)[i] = '\0';
		i++;
	}
}

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		write(1, &str[i], 1);
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
