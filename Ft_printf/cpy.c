/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_insert_word.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/19 09:35:47 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 15:25:24 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Fonction qui insert un mot dans une phrase
**	new = chaine vide de la bonne taille
**	data->s = string = chaine ou il faut insert le mot
**	index = emplacement du mot a inserer
**	word = mot a inserer
*/

char	*ft_insert_word(s_struct *data, int index, int i)
{
	size_t	len;
	char	*new;
	int		cmp;
	int		repr;

	len = ft_strlen(data->s) + ft_strlen(data->params[i]);
	len -= ft_strlen(data->argv[i]);
	new = ft_strnew(len + 1);
	cmp = 0;
	repr = index;
	ft_strncpy(new, data->s, index);
	while (data->params[i][index])
	{
		new[index] = data->params[i][cmp];
		index++;
		cmp++;
	}
	while (data->s[repr])
	{
		new[index] = data->s[repr];
		index++;
		repr++;
	}
	new[index] = '\0';
	return (new);
}

/*
char	*ft_insert_word(char *new, s_struct *data, int index, char *word)
{
	int		i;
	int		j;
	int		x;
	char	*string;

	i = 0;
	j = index;
	x = ft_strlen(data->argv[0]);
	string = ft_strdup(data->s);
	ft_strncpy(new, string, index);
	while (word[i])
	{
		new[index] = word[i];
		i++;
		index++;
	}
	j = j + x - 2;
	while (string[j])
	{
		new[index] = string[j];
		index++;
		j++;
	}
	ft_strdel(&string);
	return (new);
}*/
