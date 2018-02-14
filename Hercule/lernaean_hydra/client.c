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
	sin_client.sin_addr.s_addr = htonl(INADDR_ANY);
	sin_client.sin_port = htons(PORT);
	if (bind(sock, (struct sockaddr *)&sin_client, sizeof(sin_client)) < 0)
		perror("error bind");
}

int			main(int argc, char **argv)
{
	int		i;
	int		client;
	SOCKADDR_IN sin_client;

	if (argc != 2)
		ft_putstr("usage : ./client [message a envoyer]\n");
	else
	{
		if ((client = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
			perror("erreur creation socket");
		bind_socket(client, sin_client);
		if (connect(client, (struct sockaddr *)&sin_client, sizeof(sin_client)) < 0)
			perror("Erreur de connection");
		else
		{
			send(client, argv[1], 4, 0);
			shutdown(client, 2);
		}
		close(client);
	}
	return (i);
}
