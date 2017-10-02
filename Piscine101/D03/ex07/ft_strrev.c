/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:39:26 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/13 09:52:18 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		compteur;
	int		i;
	char	tmp;

	i = 0;
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
