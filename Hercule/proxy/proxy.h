/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proxy.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 11:30:43 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 11:30:47 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PROXY_H
# define PROXY_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <netdb.h>
# include <sys/types.h>
# include <sys/socket.h>

int				proxy(char **av);

#endif
