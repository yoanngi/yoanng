#include "server.h"

int		main(int argc, char **argv)
{
	int SOCKET;

	SOCKET = sock;

	if (sock = socket(AF_INET, SOCK_STREAM, 0) == -1)
	{
		ft_putstr("Probleme de connection\n");
		exit(0);
	}
	if (bind(socket, SOCKADDR, &mon_addr, sizeof(mon_addr)) < 0)
	{
		ft_putstr("Probleme de connection\n");
		exit(0);
	}
	listen(sock, 5);

	// reste acceptation de connection

	http://broux.developpez.com/articles/c/sockets/#
	return (0);
}
