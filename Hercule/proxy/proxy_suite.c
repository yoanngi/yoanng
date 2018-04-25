/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proxy_suite.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 11:35:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 13:34:03 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "proxy.h"

void		analyse_request(int fd, char *url, char *pro, char *req)
{
	int				flag;
	int				i;
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
		tmp = strtok(NULL, "/");
	else
		tmp = strtok(NULL, ":");
	host = gethostbyname(pro);
	printf("url = %s\n", url);
	printf("pro = %s\n", pro);
	printf("req = %s\n", req);
	printf("fd = %d\n", fd);
}
