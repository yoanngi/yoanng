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
	if ((!strncmp(req, "GET", 3)) &&
	(!strncmp(url, "http://", 7)) &&
	((!strncmp(pro, "HTTP/1.1", 8)) || (!strncmp(pro, "HTTP/1.0", 8))))
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
	client_fd = accept(fd, (struct sockaddr *)NULL, NULL);
	if (client_fd < 0)
		return (-1);
	bzero((char*)tmp, 512);
	recv(fd, tmp, 512, 0);
	check_request(client_fd, tmp);
	return (0);
}

void							check_request(int fd, char *buf)
{
	char	req[512];
	char	url[512];
	char	pro[10];

//	bzero((void *)req, 512);
//	bzero((void *)url, 512);
//	bzero((void *)pro, 10);
	sscanf(buf, "%s %s %s", req, url, pro);
	printf("sscan ok\n");
	if (verif(req, pro, url) == 1)
	{
		printf("Verif ok : url = %s\n", url);
		analyse_request(fd, url, pro);
	}
	else
	{
		printf("Verif NON ok : url = %s\n", url);
		send(fd, "Error 400: BAD REQUEST\n", 18, 0);
	}
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
	printf("Listening...\n");
	while (1)
		proxy_suite(server_socket);
	close(server_socket);
	return (0);
}
