/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   server.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 10:07:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 13:46:45 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/socket.h>
# include <unistd.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <stdio.h>

# define PORT			8888
# define BUFF_SIZE		4096

int		ft_putchar(char c);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);

#endif
