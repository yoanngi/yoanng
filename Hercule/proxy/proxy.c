/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proxy.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 11:30:21 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 14:53:03 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "proxy.h"

/*
**	Sources:
**	http://godlytalias.blogspot.fr/2013/02/simple-proxy-server-using-c.html
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
	if (((strncmp(req, "GET", 3) == 0))
	&& ((strncmp(pro, "HTTP/1.1", 8) == 0) ||
	(strncmp(pro, "HTTP/1.0", 8) == 0))
	&& (strncmp(url, "http://", 7) == 0))
		return (1);
	else
		return (0);
}

static int						proxy_suite(int fd)
{
	struct sockaddr_in		c_addr;
	socklen_t				c_len;
	char					tmp[512];
	int						client_fd;

	c_len = sizeof(c_addr);
	bzero((char *)tmp, 511);
	client_fd = accept(fd, (struct sockaddr *)&c_addr, &c_len);
	if (client_fd < 0)
	{
		printf("\nError : Connection refused\n");
		return (-1);
	}
	recv(client_fd, tmp, 511, 0);
	check_request(client_fd, tmp);
	return (0);
}

void							check_request(int fd, char *buf)
{
	char	req[300];
	char	url[300];
	char	pro[10];

	sscanf(buf, "%s %s %s", req, url, pro);
	if (verif(req, pro, url) == 1)
	{
		printf("**************************** OK\n");
		printf("type = %s\n", req);
		printf("protocole = %s\n", pro);
		printf("url = %s\n", url);
		analyse_request(fd, url, pro);
	}
	else
		send(fd, "400 : BAD REQUEST\nONLY HTTP REQUESTS ALLOWED", 18, 0);
}

int								proxy(int p)
{
	int					server_socket;
	struct sockaddr_in	s_addr;

	if ((server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		return (1);
	s_addr = ft_server_socket(p);
	if (bind(server_socket, (struct sockaddr *)&s_addr, sizeof(s_addr)) < 0)
		return (2);
	listen(server_socket, 42);
	printf("Listening...\n\n");
	while (1)
		proxy_suite(server_socket);
	close(server_socket);
	return (0);
}
