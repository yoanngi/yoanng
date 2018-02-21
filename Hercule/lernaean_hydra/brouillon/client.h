/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   client.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 10:12:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 13:02:50 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/socket.h>
# include <unistd.h>
# include <arpa/inet.h>
# include <stdio.h>

# define PORT		4242
# define BUFF_SIZE	1024

void	ft_putstr(const char *str);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);

#endif
