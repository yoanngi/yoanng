/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   server.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 10:07:56 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 15:34:21 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "server.h"

static void	bind_socket(int sock, SOCKADDR_IN sin_server)
{
	sin_server.sin_family = AF_INET;
	sin_server.sin_addr.s_addr = INADDR_ANY;
	sin_server.sin_port = htons(PORT);
	if (bind(sock, (struct sockaddr *)&sin_server, sizeof(sin_server)) < 0)
		perror("Binding Failled");
}

static int	accept_connection(int server_socket, SOCKADDR_IN sin_server)
{
	int		len;
	int		for_client;

	len = sizeof(struct sockaddr_in);
	if ((for_client = accept(server_socket, (struct sockaddr *)&sin_server,
	(socklen_t*)&len)) < 0)
		perror("Connection Failled");
	ft_putstr("Accept connection\n");
	return (for_client);
}

int		main(void)
{
	int				server;
	int				connect;
	SOCKADDR_IN		sin_server;
	char			buffer[1024];

	if ((server = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		perror("Building socket Failled");
	bind_socket(server, sin_server);
	listen(server, 5);
	ft_putstr("Listen connection OK\n");
	connect = accept_connection(server, sin_server);
	ft_putstr("Socket & Bind ok\nEn attente de message :\n");
	while (recv(server, buffer, 32, 0) > 0)
	{
		ft_putstr("Recu : ");
		ft_putstr(buffer);
		ft_putstr("\n");
	}
	ft_putstr("On en recoit rien\n");
	close(server);
	return (0);
}

// http://www.linux-france.org/article/lgazette/issue-33/lg-33-4.html
// http://broux.developpez.com/articles/c/sockets/#
// http://www.binarytides.com/server-client-example-c-sockets-linux/
