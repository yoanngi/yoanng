/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:50:12 by yoginet           #+#    #+#             */
/*   Updated: 2017/11/10 13:25:46 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		ft_read_doc(char *doc)
{
	int		fichier;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fichier = open(doc, O_RDONLY);
	if (fichier == -1)
		return (1);
	while ((ret = read(fichier, buf, BUF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	close(fichier);
	if (fichier == -1)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int err;

	if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		err = ft_read_doc(argv[1]);
		if (err == 1)
			return (1);
	}
	return (0);
}
