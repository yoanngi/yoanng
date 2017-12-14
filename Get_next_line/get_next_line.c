/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 10:05:39 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 19:25:18 by yoginet          ###   ########.fr       */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
/*
static int      ft_end_of_line(char *str, int len)
{
    int i;

    i = 0;
    while (i < len + 1 && str[i] != '\n')
        i++;
    if (str[i] == '\n')
    {
        str[i] = '\0';
        return (i);
    }
    return (-1);
}*/

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
		*line = ft_strdup(*s);
		*s = ft_strsub(cpy, 1, len - 1);
	}
	ft_strdel(&cpy);
	return (1);
}

static	char	*ft_strjoin_free(char *buf, char *s)
{
	size_t	len_buf;
	size_t	len_s;
	char	*str;

	len_buf = 0;
	len_s = 0;
	if (buf)
		len_buf = ft_strlen(buf);
	if (s)
		len_s = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (len_buf + len_s + 1));
	ft_memcpy(str, buf, len_buf);
	ft_memcpy(str + len_buf, s, len_s);
	str[len_buf + len_s] = '\0';
	free(buf);
	ft_bzero(s, BUFF_SIZE + 1);
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char		*s;
	char			buff[BUFF_SIZE + 1];
	int				retour;
	int				i;
	int				ret;

	i = 0;
	retour = 0;
	if (fd < 0 || !line || BUFF_SIZE <= 0 || (read(fd, buff, 0)) < 0)
		return (-1);
	if (!s)
	{
		while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
		{
			buff[ret] = '\0';
			s = ft_strjoin_free(s, buff);
		}
	}
	retour = ft_get_nl(&s, line, i);
	return (retour);
}
