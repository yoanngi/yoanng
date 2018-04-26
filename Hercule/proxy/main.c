/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 11:30:30 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 13:11:22 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "proxy.h"

static int		ft_usage(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (ac >= 2)
	{
		if (strcmp(av[1], "-h") == 0 || strcmp(av[1], "-help") == 0)
			return (1);
		if (strcmp(av[1], "--h") == 0 || strcmp(av[1], "--help") == 0)
			return (1);
		if (atoi(av[1]) < 0 || atoi(av[1]) > 65535)
			printf("Erreur : Port invalid\n");
	}
	return (0);
}

int				main(int ac, char **av)
{
	int		err;
	int		usage;
	int		port;

	usage = ft_usage(ac, av);
	if (usage == 1)
	{
		printf("usage: ./proxy [PORT]\n");
		return (0);
	}
	port = atoi(av[1]);
	printf("101 Proxy (Hercule Project)\n");
	err = proxy(port);
	if (err == 1)
		printf("Erreur: socket failled\n");
	if (err == 2)
		printf("Erreur: bind failled\n");
	if (err == 3)
		printf("Erreur: connection failled\n");
	return (0);
}
