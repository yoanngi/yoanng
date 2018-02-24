/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:10:30 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 10:10:32 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *chaine;

	chaine = (unsigned char*)str;
	while (n > 0)
	{
		*chaine++ = (unsigned char)c;
		n--;
	}
	return (str);
}
