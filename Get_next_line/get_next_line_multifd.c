/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 10:05:39 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 18:04:46 by yoginet          ###   ########.fr       */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

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

static int      ft_check_n(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\n' && s[i])
        i++;
    if (s[i] == '\n')
    {
        s[i] = '\0';
        return (i);
    }
    return (-1);
}

static	int		ft_check_return(char **s, char **buf, char **line)
{
	char	*cpy;
    int     i;

	*s = ft_strjoin_free(*s, *buf);
    i = ft_check_n(*s);
    if (i > -1)
    {
		*line = ft_strdup(*s);
		cpy = *s;
		*s = ft_strdup(*s + i + 1);
		free(cpy);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
    static char		*s[BUFF_SIZE + 1];
    char			*buff;
    int				retour;
    int				ret;

    retour = -1;
    buff = ft_strnew(BUFF_SIZE + 1);
    if (fd < 0 || !line || BUFF_SIZE <= 0 || (read(fd, buff, 0)) < 0)
        return (-1);
    while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
    {   
        retour = ft_check_return(&s[fd], &buff, line);
		free(buff);
		if (retour== 1)
			return (1);
		buff = ft_strnew(BUFF_SIZE);
    }
    if ((retour = ft_check_return(&s[fd], &buff, line)) == 1)
        return (1);
    else if (ft_strlen(s[fd]) > 1)
    {
        *line = ft_strdup(s[fd]);
        ft_strdel(&s[fd]);
        return (1);
    }
    return (retour);
}
