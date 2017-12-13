/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 10:05:39 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 16:32:54 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_no_return(char **s, char **line)
{
	char	*cpy;

	cpy = ft_strdup(*s);
	if (ft_strlen(*s) > 0)
	{
		*line = ft_strdup(cpy);
		ft_strdel(s);
		ft_strdel(&cpy);
		return (1);
	}
	return (0);
}

static int		ft_check_return(char **s, char **line, size_t i)
{
	size_t	len;
	char	*cpy;

	cpy = ft_strdup(*s);
	len = ft_strlen(cpy);
	if (len == 0)
		return (0);
	while (i < len + 1)
	{
		if (cpy[i] == '\n')
		{
			ft_strdel(s);
			*line = ft_strsub(cpy, 0, i);
			*s = ft_strsub(cpy, i + 1, len - i);
			if (ft_strlen(*s) <= 1)
				ft_strdel(s);
			ft_strdel(&cpy);
			return (1);
		}
		i++;
	}
	ft_strdel(&cpy);
	return (len);
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
	static char		*s = NULL;
	char			buff[BUFF_SIZE + 1];
	int				retour;
	size_t			i;
	int				ret;

	i = 0;
	retour = -1;
	if (fd < 0 || !line || BUFF_SIZE <= 0 || (read(fd, buff, 0)) < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[BUFF_SIZE] = '\0';
		s = ft_strjoin_free(s, buff);
		if ((retour = ft_check_return(&s, line, i) == 1))
			return (1);
	}
	if (!s)
		return (0);
	else if ((retour = ft_check_return(&s, line, i)) == 1)
		return (1);
	else
		retour = ft_no_return(&s, line);
	return (retour);
}
