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

void	ft_connect(void)
{
	SOCKET		sock;
	SOCKADDR_IN sin;
	SOCKET		c_sock;
	SOCKADDR_IN c_sin;
	int			sock_err;
	socklen_t recsize = sizeof(c_sin);
	char		buffer[50];

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock != INVALID_SOCKET)
	{
		printf("SERVER -> La socket %d est maintenant ouverte en mode TCP/IP\n", sock);
		sin.sin_addr.s_addr = htonl(INADDR_ANY);		/* Adresse IP automatique */
		sin.sin_family = AF_INET;						/* Protocole familial (IP) */
		sin.sin_port = htons(PORT);						/* Listage du port */
		sock_err = bind(sock, (SOCKADDR*)&sin, sizeof(sin));
		if(sock_err != SOCKET_ERROR)
		{
			sock_err = listen(sock, 5);
			printf("Listage du port %d...\n", PORT);
			/* Attente pendant laquelle le client se connecte */
			printf("Patientez pendant que le client se connecte sur le port %d...\n", PORT);
			c_sock = accept(sock, (SOCKADDR*)&c_sin, &recsize);
			printf("Un client se connecte avec la socket %d de %s:%d\n", c_sock, inet_ntoa(c_sin.sin_addr), htons(c_sin.sin_port));
			/* Si l'on reçoit des informations : on les affiche à l'écran */
			if(recv(c_sock, buffer, 50, 0) != SOCKET_ERROR)
				printf("Recu : %s\n", buffer);
		}
		printf("Fermeture de la socket...\n");
		close(sock);
		printf("Fermeture du serveur terminee\n");
		getchar();
	}
}


int		main(void)
{
	int		server;
	int		client;

	server = ft_initialise();
	bind_socket(server, INADDR_ANY, PORT_NBR);
	listen(server, 5);
	ft_putendl_fd("Waiting for connections...", STDOUT);
	client = accept_connection(server);
	receive_message(client);
	return (0);
}
