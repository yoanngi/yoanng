#include "proxy.h"

static struct sockaddr_in		ft_server_socket(int p)
{
	struct sockaddr_in		adress;

	bzero((char*)&adress, sizeof(adress));
	adress.sin_family = AF_INET;
	adress.sin_port = htons(p);
	adress.sin_addr.adress = INADDR_ANY;
	return (adress);
}

static int						proxy_suite(int fd)
{
	(void)fd;
	return (0);
}

int								proxy(char **av)
{
	int					server_socket;
	int					client_fd;
	struct sockaddr_in	s_addr;
	struct sockaddr_in	c_addr;

	(void)av;
	s_addr = ft_server_socket(8080);
	if ((server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		return (1);
	if (bind(server_socket, (struct sockaddr *)&s_addr, sizeof(s_addr)) < 0)
		return (2);
	listen(server_socket, 10);
	if ((client_fd = accept(server_socket, (struct sockaddr *)NULL, NULL)) < 0)
		return (3);
	if (proxy_suite(client_fd) == 1)
		return (4);
	close(client_fd);
	close(server_socket);
	return (0);
}
