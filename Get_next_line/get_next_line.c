/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 10:52:49 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/03 16:34:03 by yoginet          ###   ########.fr       */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_get_nl(char *s, char **line)
{
    int     i;
    char    cpy;

    i = 0;
    while (s[i] && s[i] != '\n')
        i++;
    if (i == 0 || s == NULL)
        (*line) = ft_strdup("");
    else
    {
        (*line) = ft_strsub(s, 0, i);
		s = &s[i + 1];
        return (1);
    }
	return (0);
}

static char		*ft_read_doc(const int fd, char *s, char *buf)
{
	int	ret;
    int compt;

    compt = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[ret] = '\0';
        s = ft_strjoin(s, buf);
	}
	return (s);
}

static int		ft_error(const int fd, char **line, char **s)
{
	if (fd < 0)
		return (-1);
	if (!(*s = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*s;
	char			buf[BUFF_SIZE + 1];

	if (ft_error(fd, line, &s) == -1)
		return (-1);
    if (*s)
		ft_strcpy(*line, s);
	s = ft_read_doc(fd, s, buf);
    if (ft_get_nl(s, line) == 1)
        return (1);
	return (0);
}
