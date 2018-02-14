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

#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define PORT 3000

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

int			ft_connect(char *str)
{
	SOCKET		sock;
	SOCKADDR_IN sin;
	char		buf[100];
	int			i;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORT);
	if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
	{
		printf("Connection à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
		printf("Pour quitter, taper <exit>\n");
		while (i == 1)
		{
			read(1, buf, 100);
			send(sock, buf, strlen(buf), 0);
			printf("requete envoyer : %s\n", buf);
			if (strcmp(buf, "exit") == 0)
				i = 0;
		}
		shutdown(sock, 2);
	}
	else
		printf("ERROR ->Impossible de se connecter\n");
	close(sock);
	return EXIT_SUCCESS;
}

int			ft_initialise_connection(char *str)
{
	ft_connect(str);
	return (0);
}

int			main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		printf("usage : ./client [message a envoyer]\n");
	else
		i = ft_initialise_connection(argv[1]);
	return (i);
}
