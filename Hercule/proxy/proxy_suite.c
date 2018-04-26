/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proxy_suite.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 11:35:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 14:52:41 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "proxy.h"

static int		get_connect(char *domain)
{
	struct sockaddr_in		host;
	struct hostent			*h;
	int						fd_sock;

	h = gethostbyname(domain);
	bzero((char*)&host, sizeof(host));
	host.sin_port = htons(80);
	host.sin_family = AF_INET;
	bcopy((char*)h->h_addr, (char*)&host.sin_addr.s_addr, h->h_length);
	fd_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd_sock < 0)
	{
		printf("\nError creating Socket.... exiting\n");
		return (0);
	}
	if ((connect(fd_sock, (struct sockaddr*)&host, sizeof(struct sockaddr)))
	< 0)
	{
		printf("\nError in connecting to remote server");
		return (0);
	}
	printf("[Connected] domain:[ %s ] IP:[ %s ]\n\n", domain,
	inet_ntoa(host.sin_addr));
	return (fd_sock);
}

static char		*get_domain(char *url)
{
	char	*ret;
	char	*tmp;

	if (url == NULL)
		return (NULL);
	tmp = strdup(url);
	ret = strtok(tmp, "//");
	ret = strdup(strtok(NULL, "/"));
	free(tmp);
	tmp = NULL;
	return (ret);
}

void			analyse_request(int fd, char *url, char *pro)
{
	char	buf[1024];
	char	*domain;
	int		fdc;
	int		i;

	domain = get_domain(url);
	fdc = get_connect(domain);
	bzero((char*)buf, sizeof(buf));
	sprintf(buf, "GET / %s\r\nHost: %s\r\nConnection: close\r\n\r\n",
	pro, domain);
	i = send(fdc, buf, strlen(buf), 0);
	if (i < 0)
		printf("\nError writing to socket\n");
	else
	{
		while (i > 0)
		{
			bzero((char*)buf, 1024);
			i = recv(fdc, buf, 1024, 0);
			if (!(i <= 0))
				if (send(fd, buf, i, 0) < 0)
					printf("Error send\n");
		}
	}
	close(fdc);
}
