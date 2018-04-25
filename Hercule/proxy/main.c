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
		if (atoi(av[1]) < 0 || atoi(av[1] > 65000))
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
		printf("usage: ./proxy [PORT (0 - 65000)]\n");
		return (0);
	}
	port = atoi(av[1]);
	err = proxy(port);
	if (err == 1)
		printf("Erreur: socket failled\n");
	if (err == 2)
		printf("Erreur: bind failled\n");
	if (err == 3)
		printf("Erreur: connection failled\n");
	return (0);
}
