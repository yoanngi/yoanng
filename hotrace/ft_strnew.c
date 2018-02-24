/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:16:18 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 10:16:19 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strnew(size_t size)
{
	char	*mal;

	mal = (char *)malloc(sizeof(char) * (size + 1));
	if (!mal)
		return (NULL);
	ft_memset(mal, '\0', size + 1);
	return (mal);
}
