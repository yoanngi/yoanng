/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 15:02:19 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv)
{
	int		ret;
	char	*line;
	char	buff[BUFF_SIZE];
	int		fd;

	ret = 0;
	(void)argc;
	(void)argv;
	fd = 2;
	line = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[ret] = '\0';
		ft_putendl(buff);
		ft_bzero(buff, ft_strlen(buff));
	}
	return (0);
}
