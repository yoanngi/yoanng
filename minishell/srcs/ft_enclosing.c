/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_enclosing.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/21 11:13:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 13:02:40 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Search c && d in string
*/

int			ft_search_enclosing(char *str, char c, char d)
{
	int		i;
	int		prime;
	int		two;
	int		len;

	i = 0;
	prime = 0;
	two = 0;
	len = ft_strlen(str);
	if (len == 1 && str[0] == c)
		return (1);
	while (str[i])
	{
		if (str[i] == c)
			prime++;
		if (str[i] == d)
			two++;
		i++;
	}
	if (prime == 0 || prime == two)
		return (0);
	if (c == d && (prime % 2 != 0))
		return (1);
	return (1);
}
