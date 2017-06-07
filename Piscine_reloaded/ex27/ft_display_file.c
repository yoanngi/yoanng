/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yginet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 16:24:10 by yginet            #+#    #+#             */
/*   Updated: 2016/07/21 16:33:45 by yginet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1

void	ft_putchar(int i, char c)
{
	write(i, &c, 1);
}

void	ft_putstr(int ii, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(ii, str[i]);
		i++;
	}
}

void	ft_printdoc(char *doc)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(doc, O_RDONLY);
	if (fd == -1)
		return ;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(1, buf);
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argc <= 1)
	{
		ft_putstr(2, "File name missing.\n");
		return (0);
	}
	else if (argc > 2)
	{
		ft_putstr(2, "Too many arguments.\n");
		return (0);
	}
	ft_printdoc(argv[1]);
	return (0);
}
