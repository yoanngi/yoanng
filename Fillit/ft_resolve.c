/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resolv.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 14:02:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 13:35:16 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_char(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] == '.' || s[i] == '#' || s[i] == '\n')
	{
		i++;
		if (s[i] == '\0')
			return (1);
		if (i == 21)
			return (1);
	}
	return (0);
}

static int		ft_check_retour(const char *s, size_t len)
{
	int		i;
	int		n;

	n = -1;
	while (n < (int)len)
	{
		i = 0;
		while (i < 4)
		{
			n += 5;
			if (s[n] != '\n')
				return (0);
			i++;
		}
		n++;
		if (!(s[n] == '\n' || s[n] == '\0'))
			return (0);
	}
	return (1);
}

static int		ft_check_diese(const char *s)
{
	int i;
	int j;
	int x;

	i = 0;
	j = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] == '#')
			j++;
		if (s[i] == '.')
			x++;
		i++;
	}
	if (j == 4 && x == 12)
		return (1);
	return (0);
}

static int		ft_check_valid(const char *s)
{
	size_t	len;
	int		exit;

	len = ft_strlen(s);
	exit = 1;
	if (len < 20)
		exit = 0;
	if (len == 20 && ft_check_diese(s) == 1)
	{
		ft_compact_unit(s);
		return (0);
	}
	if (len == 20 && ft_check_diese(s) == 0)
		exit = 0;
	if (ft_check_char(s) == 0)
		exit = 0;
	if (ft_check_retour(s, len) == 0)
		exit = 0;
	if (exit == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

void			ft_resolve(char *doc)
{
	t_list	*tetris;
	t_list	*lst;
	char	*chaine_tetris;
	size_t	len;

	len = 21;
	chaine_tetris = ft_convert_str(doc);
	if (ft_check_valid(chaine_tetris) == 1)
	{
		tetris = (t_list *)malloc(sizeof(t_list));
		lst = tetris;
		while (chaine_tetris != '\0')
		{
			tetris->content = ft_strsub(chaine_tetris, 0, len);
			tetris->content_size = ft_strlen(tetris->content);
			if (ft_strlen(chaine_tetris) > 20)
				tetris->next = ft_lstnew(tetris->content,
	ft_strlen(chaine_tetris));
			tetris = tetris->next;
			chaine_tetris = ft_resize_str(chaine_tetris, len);
		}
		ft_check_list(lst);
	}
}
