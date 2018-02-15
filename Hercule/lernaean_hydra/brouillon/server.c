/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   server.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 13:31:48 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 15:42:08 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "server.h"

static void		bind_socket(int sock, struct sockaddr_in server)
{
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(PORT);
	if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
		perror("Binding Failled");
}

static int		ft_pingornot(int sock_client)
{
	int		read_size;
	char	*tmp;
	char	msg[512];

	while ((read_size = recv(sock_client, msg, 512, 0)) > 0)
	{
		ft_putstr("DEBUG -> message recu =\n");
		ft_putstr(msg);
		write(1, &msg[0], 1);
		ft_putstr("\n");
		write(1, &msg[1], 1);
		ft_putstr("\n");
		write(1, &msg[2], 1);
		ft_putstr("\n");
		write(1, &msg[3], 1);
		ft_putstr("\n");
		write(1, "end", 4);
		if (msg[0] == 'p' && msg[1] == 'i' && msg[2] == 'n' && msg[3] == 'g' && msg[4] == 3)
		{
			ft_putstr("HERE\n");
			ft_bzero(msg, ft_strlen(msg));
			ft_strcpy(msg, "pong\n");
			write(sock_client, msg, ft_strlen(msg));
			write(sock_client, msg, ft_strlen(msg));
		}
		else
		{
			ft_bzero(msg, ft_strlen(msg));
		//	ft_strcpy(msg, "Commande Invalide\n");
			write(sock_client, msg, ft_strlen(msg));
		}
	}
	if (read_size == 0)
		fflush(stdout);
	if (read_size == -1)
		perror("recv failed");
	return (0);
}

int				main(int argc, char **argv)
{
	int					sock_server;
	int					sock_client;
	int					c;
	struct sockaddr_in	server;
	struct sockaddr_in	client;

	if ((sock_server = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		perror("building socket Failled");
	bind_socket(sock_server, server);
	listen(sock_server, 3);
	c = sizeof(struct sockaddr_in);
	if ((sock_client = accept(sock_server, (struct sockaddr *)&sock_client,
	(socklen_t*)&c)) < 0)
	{
		perror("accept failed");
		return (1);
	}
	ft_pingornot(sock_client);
	close(sock_server);
	close(sock_client);
	return (0);
}
