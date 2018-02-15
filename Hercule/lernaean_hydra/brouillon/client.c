/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   client.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 13:34:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 15:42:10 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "client.h"

static void		bind_socket(int sock, struct sockaddr_in *client)
{
	client->sin_family = AF_INET;
	client->sin_addr.s_addr = inet_addr("127.0.0.1");
	client->sin_port = htons(PORT);
}

static int		ft_send_message(int sock)
{
	char				message[1000];
	char				server_reply[1000];

	ft_putstr("You are connected\nTape < q > + ENTER for exit\n");
	while (message[0] != 'q' && message[1] != '\n')
	{
		ft_putstr("Please enter your message :\n");
		scanf("%s", message);
		if (send(sock, message, ft_strlen(message), 0) < 0)
		{
			perror("Send failed");
			return (1);
		}
		if (recv(sock, server_reply, 999, 0) < 0)
		{
			perror("recv failed");
			return (1);
		}
		if (message[0] != 'q' && message[1] != '\n')
		{
			ft_putstr("Server reply :\n");
			ft_putstr(server_reply);
		}
		ft_bzero(message, ft_strlen(message));
	}
	return (0);
}

int				main(int argc, char **argv)
{
	int					sock;
	struct sockaddr_in	server;

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		perror("Socket Failled");
	bind_socket(sock, &server);
	if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		perror("Connection failed !");
		return (1);
	}
	ft_send_message(sock);
	close(sock);
	return (0);
}
