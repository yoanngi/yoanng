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

static int	analyse_suite(int port)
{
	struct sockaddr_in		host_addr;
	char					buffer[512];
	int						sockfd1;
	int						newsockfd1;

	bzero((char*)&host_addr,sizeof(host_addr));
	host_addr.sin_port=htons(port);
	host_addr.sin_family=AF_INET;
	bcopy((char*)host->h_addr,(char*)&host_addr.sin_addr.s_addr,host->h_length);

	sockfd1 = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	newsockfd1 = connect(sockfd1,(struct sockaddr*)&host_addr,sizeof(struct sockaddr));
	sprintf(buffer,"\nConnected to %s  IP - %s\n",t2,inet_ntoa(host_addr.sin_addr));
	if(newsockfd1 < 0)
		error("Error in connecting to remote server");
	printf("\n%s\n",buffer);
	send(newsockfd,buffer,strlen(buffer),0);
	bzero((char*)buffer,sizeof(buffer));
	// line 130
}

void		analyse_request(int fd, char *url, char *pro, char *req)
{
	int				flag;
	int				i;
	int				port;
	char			*tmp;
	struct hostent	*host;

	flag = 0;
	i = 7;
	tmp = NULL;
	while (i < strlen(pro) || flag == 0)
	{
		if (pro[i] == ':')
			flag = 1;
		i++;
	}
	tmp = strtok(req, "//");
	if (flag == 0)
	{
		port = 80;
		tmp = strtok(NULL, "/");
	}
	else
		tmp = strtok(NULL, ":");
	host = gethostbyname(pro);
	if (flag == 1)
	{
		tmp = strtok(NULL, "/");
		port = atoi(tmp);
	}
	strcat(url, "^]");
	tmp = strtok(url, "//");
	tmp = strtok(NULL, "/");
	if (tmp != NULL)
		tmp = strtok(NULL, "^]");
	printf("path = %s, port = %d\n", tmp, port);
	// line 116
	analyse_suite(port);
}
