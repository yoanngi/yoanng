/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   server.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 10:07:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 15:25:14 by yoginet     ###    #+. /#+    ###.fr     */
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

void	ft_putstr(const char *str);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dst, const char *src);

#endif
