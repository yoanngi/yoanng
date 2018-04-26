/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proxy.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 11:30:21 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 13:26:55 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "proxy.h"

/*
** http://godlytalias.blogspot.fr/2013/02/simple-proxy-server-using-c.html
** https://forum.hardware.fr/hfr/Programmation/C/socket-programmer-proxy-sujet_88089_1.htm
** https://stackoverflow.com/questions/226784/how-to-create-a-simple-proxy-in-c
*/

static struct sockaddr_in		ft_server_socket(int p)
{
	struct sockaddr_in		adress;

	bzero((char*)&adress, sizeof(adress));
	adress.sin_family = AF_INET;
	adress.sin_port = htons(p);
	adress.sin_addr.s_addr = INADDR_ANY;
	return (adress);
}

static int						verif(char *req, char *pro, char *url)
{
	if (strncmp(req, "GET", 3) != 0)
		return (0);
	if (strncmp(url, "http://", 7) != 0)
		return (0);
	if (strncmp(pro, "HTTP/1.1", 8) != 0 || strncmp(pro, "HTTP/1.0", 8) != 0)
		return (0);
	return (1);
}

static int						proxy_suite(int fd)
{
	struct sockaddr_in		c_addr;
	socklen_t				c_len;
	char					tmp[512];
	int						client_fd;

	c_len = sizeof(c_addr);
	if ((client_fd = accept(fd, (struct sockaddr *)NULL, NULL)) < 0)
		return (-1);
	bzero((char*)tmp, 512);
	if ((recv(fd, tmp, 512, 0)) < 0)
		return (-1);
	check_request(client_fd, tmp);
	return (0);
}

void							check_request(int fd, char *buf)
{
	char	req[512];
	char	url[512];
	char	pro[10];

	bzero((void *)req, 512);
	bzero((void *)url, 512);
	bzero((void *)pro, 10);
	sscanf(buf, "%s %s %s", req, url, pro);
	if (verif(req, pro, url) == 1)
		analyse_request(fd, url, pro);
	else
		send(fd, "Error 400: BAD REQUEST\n", 18, 0);
}

int								proxy(int p)
{
	int					server_socket;
	int					ret;
	struct sockaddr_in	s_addr;

	ret = 0;
	if ((server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		return (1);
	s_addr = ft_server_socket(p);
	if (bind(server_socket, (struct sockaddr *)&s_addr, sizeof(s_addr)) < 0)
		return (2);
	listen(server_socket, 42);
	while (ret == 0)
		ret = proxy_suite(server_socket);
	if (ret == -1)
		return (3);
	close(server_socket);
	return (0);
}
