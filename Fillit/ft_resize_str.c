/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resize_str.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 10:40:44 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:55:56 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_resize_str(char *str, size_t len)
{
	char	*cpy;
	size_t	n;

	n = ft_strlen(str);
	cpy = (char *)malloc(sizeof(char) * (n - len));
	if (cpy == NULL)
		return (NULL);
	cpy = ft_strsub(str, len, n - len);
	free(str);
	return (cpy);
}
