/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_str.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 14:51:48 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 13:01:18 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static	size_t	ft_len_doc(char *doc)
{
	int		fichier;
	int		ret;
	char	buf[BUF_SIZE + 1];
	size_t	len;

	len = 0;
	fichier = open(doc, O_RDONLY);
	if (fichier == -1)
		return (1);
	while ((ret = read(fichier, buf, BUF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		len++;
	}
	close(fichier);
	if (fichier == -1)
		return (len = 1);
	return (len);
}

static	char	ft_insert_doc(char *doc, char *str)
{
	int		fichier;
	int		ret;
	char	buf[BUF_SIZE + 1];
	size_t	index;

	index = 0;
	fichier = open(doc, O_RDONLY);
	if (fichier == -1)
		return (1);
	while ((ret = read(fichier, buf, BUF_SIZE)) != 0)
	{
		str[index] = *buf;
		index++;
		buf[ret] = '\0';
	}
	str[index] = '\0';
	close(fichier);
	if (fichier == -1)
		return (1);
	return (*str);
}

char			*ft_convert_str(char *doc)
{
	char *str;

	str = (char *)malloc(sizeof(char) * ft_len_doc(doc) + 1);
	if (str == NULL)
		return (NULL);
	ft_insert_doc(doc, str);
	return (str);
}
