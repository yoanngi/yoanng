/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   server.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 10:07:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 13:18:10 by yoginet     ###    #+. /#+    ###.fr     */
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

# define PORT			4242
# define BUFF_SIZE		1024

void	ft_bzero(void *s, size_t n);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strnew(size_t size);
void	*ft_memset(void *str, int c, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
