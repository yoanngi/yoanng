/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 10:52:49 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 19:16:04 by yoginet          ###   ########.fr       */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_get_nl(char *s, char **line)
{
    int     i;
    char    cpy;

    i = 0;
    while (s[i] || s[i] != '\n')
        i++;
    if (i > 0)
    {
        *line = ft_strsub(s, 0, i);
        return (1);
    }
    else
        *line = ft_strnew("");
	return (0);
}

static char     *ft_realloc(char *str, int size)
{
    char    *cpy;

    if (size == 0 || !str)
        return (NULL);
    if (!(cpy = (char *)malloc(sizeof(char) * size)))
        return (NULL);
    ft_strcpy(cpy, str);
    free(str);
    return (cpy);
}

static char		*ft_read_doc(const int fd, char *s, char *buf, int index)
{
	int	ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
        index += BUFF_SIZE;
		buf[ret] = '\0';
        ft_strjoin(s, buf);
        s = ft_realloc(s, index + BUFF_SIZE);
	}
	return (s);
}

static int		ft_error(const int fd, char **line, char *s)
{
	if (fd < 0)
		return (1);
    if (!line)
        return (1);
    s = ft_strnew(BUFF_SIZE);
	if (s == NULL)
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*s;
    static int      index;
	char			buff[BUFF_SIZE + 1];

    index = 0;
	if (ft_error(fd, line, s) == 1)
		return (-1);
	s = ft_read_doc(fd, s, buff, index);
    if (ft_get_nl(s, line) == 1)
        return (1);
	return (0);
}
