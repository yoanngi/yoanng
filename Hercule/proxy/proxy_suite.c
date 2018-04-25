/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proxy_suite.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 11:35:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 14:26:55 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "proxy.h"

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

}
