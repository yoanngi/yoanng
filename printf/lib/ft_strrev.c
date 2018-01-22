/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:16:49 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 10:16:50 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str, int i)
{
	int		compteur;
	char	tmp;

	compteur = ft_strlen(str);
	compteur -= 1;
	while (compteur > i)
	{
		tmp = str[compteur];
		str[compteur] = str[i];
		str[i] = tmp;
		i++;
		compteur--;
	}
	return (str);
}
