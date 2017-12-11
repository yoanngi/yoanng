/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 10:29:54 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 16:21:00 by yoginet          ###   ########.fr       */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_get_nl(char **s, char **line, int i)
{
	int		len;
	char	*cpy;

	cpy = ft_strdup(*s);
	len = ft_strlen(cpy);
	ft_strdel(s);
	while (i < len + 1 && cpy[i] != '\n')
		i++;
	if (len == 0)
		return (0);
	else if (i > 0)
	{
		*line = ft_strsub(cpy, 0, i);
		*s = ft_strsub(cpy, i + 1, len - i);
	}
	else
	{
		*line = ft_strdup("");
		*s = ft_strsub(cpy, 1, len - 1);
	}
	ft_strdel(&cpy);
	return (1);
}

static char		*ft_realloc(char *str, int size)
{
	char	*cpy;

	if (size == 0 || !str)
		return (NULL);
	cpy = ft_strdup(str);
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_strcpy(str, cpy);
	ft_strdel(&cpy);
	str[size] = '\0';
	return (str);
}

static char		*ft_read_doc(const int fd, char *s, char *buf)
{
	int	ret;
	int	index;

	index = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		if (index == 0)
			s = ft_strdup(buf);
		else
			s = ft_strjoin(s, buf);
		index += BUFF_SIZE;
		ft_realloc(s, (index + BUFF_SIZE));
	}
    free(buf);
	return (s);
}

int				get_next_line(const int fd, char **line)
{
	static char		*s;
	char			buff[BUFF_SIZE + 1];
	int				retour;
	int				i;

	i = 0;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!s)
		s = ft_read_doc(fd, s, buff);
	retour = ft_get_nl(&s, line, i);
	if (retour == 0 && s)
		ft_strdel(&s);
	return (retour);
}
