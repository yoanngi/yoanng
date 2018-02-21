/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   server.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 13:31:48 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 15:49:48 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "server.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void		ft_bind_socket(int sock, struct sockaddr_in server)
{
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(PORT);
	if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
		perror("Binding Failled");
}

static int		ft_check(char **msg, int sock_client)
{
	if (ft_strncmp(*msg, "ping", ft_strlen(*msg)) == 0)
	{
		ft_bzero(*msg, BUFF_SIZE - 1);
		ft_strcpy(*msg, "pong pong");
		write(sock_client, *msg, 9);
	}
	if (ft_strncmp(*msg, "ping", 4) == 0 && ft_strlen(*msg) == 6)
	{
		ft_bzero(*msg, BUFF_SIZE - 1);
		ft_strcpy(*msg, "pong pong");
		write(sock_client, *msg, 9);
	}
	else
	{
		ft_bzero(*msg, BUFF_SIZE - 1);
		write(sock_client, *msg, 2);
	}
	return (0);
}

static int		ft_pingornot(int sock_client, int sock_server, int c)
{
	int		read_size;
	char	*msg;

	msg = ft_strnew(BUFF_SIZE);
	if ((sock_client = accept(sock_server, (struct sockaddr *)&sock_client,
	(socklen_t*)&c)) < 0)
		return (1);
	while (1)
	{
		while ((read_size = recv(sock_client, msg, BUFF_SIZE - 1, 0)) > 0)
			ft_check(&msg, sock_client);
		if ((sock_client = accept(sock_server, (struct sockaddr *)&sock_client,
	(socklen_t*)&c)) < 0)
			return (1);
		if (read_size == -1)
			return (1);
	}
	free(&msg);
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
	ft_bind_socket(sock_server, server);
	listen(sock_server, 3);
	c = sizeof(struct sockaddr_in);
	if (ft_pingornot(sock_client, sock_server, c) == 1)
		perror("Error");
	close(sock_server);
	close(sock_client);
	return (0);
}
