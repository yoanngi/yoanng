/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 10:29:54 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 15:30:32 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_get_nl(char *s, char **line)
{
	int		i;
	char	cpy;

	i = 0;
	while (s[i] != '\0' || s[i] != '\n')
		i++;
	ft_putnbr(i);
	if (i > 0)
	{
		*line = ft_strsub(s, 0, i);
		free(s);
		return (1);
	}
	else
		*line = ft_strdup("");
	return (0);
}

static char		*ft_realloc(char *str, int size)
{
	char	*cpy;

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
		buf[ret] = '\0';
		if (index == 0)
		{
			s = ft_strdup(buf);
		}
		s = ft_strjoin(s, buf);
		index += BUFF_SIZE;
		ft_realloc(s, (index + BUFF_SIZE));
	}
	return (s);
}

static int		ft_error(const int fd, char **line, char *s)
{
	if (fd < 0)
		return (1);
	if (!line)
		return (1);
	s = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (s == NULL)
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*s;
	static int		index;
	char			buff[BUFF_SIZE + 1];

	index = 0;
	if (ft_error(fd, line, s) == 1)
		return (-1);
	s = ft_read_doc(fd, s, buff, index);
	if (ft_get_nl(s, line) == 1)
		return (1);
	return (0);
}
