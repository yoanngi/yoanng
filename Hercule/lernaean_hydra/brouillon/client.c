/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   client.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 13:34:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 15:36:28 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "client.h"

static void		ft_bind_socket(int sock, struct sockaddr_in *client)
{
	client->sin_family = AF_INET;
	client->sin_addr.s_addr = inet_addr("127.0.0.1");
	client->sin_port = htons(PORT);
}

static void		ft_send_message(int sock, char *message)
{
	while (1)
	{
		ft_bzero(message, BUFF_SIZE - 1);
		ft_putstr("Please enter your word : ");
		scanf("%s", message);
		if (send(sock, message, ft_strlen(message), 0) < 0)
		{
			perror("Send failed");
			return ;
		}
		ft_bzero(message, BUFF_SIZE - 1);
		if (recv(sock, message, BUFF_SIZE - 1, 0) < 0)
		{
			perror("recv failed");
			return ;
		}
		ft_putstr("Server reply : ");
		ft_putstr(message);
		ft_putstr("\n");
	}
}

int				main(int argc, char **argv)
{
	int					sock;
	struct sockaddr_in	server;
	char				message[BUFF_SIZE];

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socket Failled");
		return (1);
	}
	ft_bind_socket(sock, &server);
	if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		perror("Connection failed !");
		return (1);
	}
	ft_send_message(sock, message);
	close(sock);
	return (0);
}
