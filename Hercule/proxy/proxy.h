/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proxy.h	                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 14:59:03 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 15:52:52 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PROXY_H
# define PROXY_H

# include <stdio.h>
# include<stdio.h>
# include<string.h>
# include<sys/socket.h>
# include<arpa/inet.h>
# include<unistd.h>

int				proxy(char **av);

#endif
