/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   client.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 10:11:49 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 15:34:24 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "client.h"

static void	bind_socket(int sock, SOCKADDR_IN sin_client)
{
	sin_client.sin_family = AF_INET;
	sin_client.sin_addr.s_addr = inet_addr("127.0.0.1");
	sin_client.sin_port = htons(PORT);
	if (bind(sock, (struct sockaddr *)&sin_client, sizeof(sin_client)) < 0)
		perror("error bind");
}

int			main(int argc, char **argv)
{
	int		i;
	int		client;
	int		for_server;
	SOCKADDR_IN sin_client;

	if (argc != 2)
		ft_putstr("usage : ./client [message a envoyer]\n");
	else
	{
		if ((client = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
			perror("Socket Failled");
		ft_putstr("Socket ok\n");
		bind_socket(client, sin_client);
		ft_putstr("Bind ok\n");
		if (connect(client, (struct sockaddr *)&sin_client, sizeof(sin_client)) < 0)
			perror("Connection Failled");
		ft_putstr("Envoie du message :\n");
		send(client, argv[1], ft_strlen(argv[1]), 0);
		ft_putstr("Close Connection\n");
		close(client);
	}
	return (i);
}
