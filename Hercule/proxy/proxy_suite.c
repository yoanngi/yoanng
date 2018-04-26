/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proxy_suite.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 11:35:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 15:11:43 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "proxy.h"

static char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (s == 0)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (s[start] && i != len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

static int		get_connect(char	*domain)
{
	struct sockaddr_in		host;
	struct hostent			*h;
	int						fd_sock;
	int						i;

	h = gethostbyname(domain);
	bzero((char*)&host, sizeof(host));
	host.sin_port = htons(80);
	host.sin_family = AF_INET;
	bcopy((char*)h->h_addr, (char*)&host.sin_addr.s_addr, h->h_length);
	fd_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	i = connect(fd_sock, (struct sockaddr*)&host, sizeof(struct sockaddr));
	if (i < 0)
	{
		printf("Error in connecting to remote server");
		return (0);
	}
	printf("Connected to %s [ %s ]\n\n", domain, inet_ntoa(host.sin_addr));
	return (fd_sock);
}

static char		*get_domain(char *url)
{
	char	*ret;
	char	*tmp;

	tmp = strdup(url);
	ret = strtok(tmp, "//");
	ret = strdup(strtok(NULL, "/"));
	free(tmp);
	tmp = NULL;
	return (ret);
}

static char		*get_path(char *url)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strsub(url, 8, strlen(url) - 8);
	ret = strchr(tmp, '/');
	free(tmp);
	tmp = NULL;
	return (ret);
}

void			analyse_request(int fd, char *url, char *pro)
{
	char	buf[512];
	char	*path;
	char	*domain;
	int		fdc;
	int		i;

	domain = get_domain(url);
	path = get_path(url);
	fdc = get_connect(domain);
	bzero((char*)buf, sizeof(buf));
	sprintf(buf, "GET %s %s\r\nHost: %s\r\nConnection: close\r\n\r\n",
	path, pro, domain);
	i = send(fdc, buf, strlen(buf), 0);
	if (i < 0)
	{
		printf("Error: socket");
		return ;
	}
	i = 1;
	while (i > 0)
	{
		bzero((char*)buf, 512);
		i = recv(fdc, buf, 512, 0);
		if (i > 0)
			send(fd, buf, i, 0);
	}
	close(fdc);
}
