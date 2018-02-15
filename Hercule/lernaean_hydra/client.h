/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   client.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 10:12:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 10:12:45 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/socket.h>
# include <unistd.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <stdio.h>

# define INVALID_SOCKET	-1
# define PORT			3000
# define BUFF_SIZE		4096

typedef struct sockaddr_in SOCKADDR_IN;

void	ft_putstr(char *str);
size_t	ft_strlen(char *str);

#endif
