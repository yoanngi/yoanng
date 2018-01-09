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
	char	*tmp;
	char	*s;
	char	*word;
	int		lo;

	len = ft_strlen(data->params[i]) + ft_strlen(data->s) - ft_strlen(data->argv[i]);
	lo = 0;
	tmp = ft_strnew(len + 1);
	s = ft_strdup(data->s);
	word = ft_strdup(data->argv[i]);
	while (lo != len)
	{
		tmp[lo] = s[lo];
		lo++;
		if (lo == index)
		{
			;
		}
	}


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
