#include "proxy.h"


/*
** http://godlytalias.blogspot.fr/2013/02/simple-proxy-server-using-c.html
** https://forum.hardware.fr/hfr/Programmation/C/socket-programmer-proxy-sujet_88089_1.htm
*/

static void						proxy_suite(int fd)
{
	void(fd);
}

static struct sockaddr_in		ft_server_socket(int p)
{
	struct sockaddr_in		adress;

	bzero((char*)&adress, sizeof(adress));
	adress.sin_family = AF_INET;
	adress.sin_port = htons(p);
	adress.sin_addr.s_addr = INADDR_ANY;
	return (adress);
}

int								proxy(int p)
{
	int					server_socket;
	int					client_fd;
	struct sockaddr_in	s_addr;
	struct sockaddr_in	c_addr;

	s_addr = ft_server_socket(p);
	if ((server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		return (1);
	if (bind(server_socket, (struct sockaddr *)&s_addr, sizeof(s_addr)) < 0)
		return (2);
	listen(server_socket, 42);
	if ((client_fd = accept(server_socket, (struct sockaddr *)NULL, NULL)) < 0)
		return (3);
	proxy_suite(client_fd);
	close(client_fd);
	close(server_socket);
	return (0);
}
