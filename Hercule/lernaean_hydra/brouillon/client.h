/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   client.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 10:12:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 13:49:37 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/socket.h>
# include <unistd.h>
# include <arpa/inet.h>
# include <stdio.h>

# define PORT 8888
# define BUFF_SIZE 1024

int		ft_putchar(char c);
void	ft_putstr(char *str);
size_t	ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);

#endif
