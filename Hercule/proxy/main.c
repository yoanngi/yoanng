#include "proxy.h"

static int		ft_usage(int ac, char **av)
{
	if (ac >= 2)
	{
		if (strcmp(av[1], "-h") == 0 || strcmp(av[1], "-help") == 0)
			return (1);
		if (strcmp(av[1], "--h") == 0 || strcmp(av[1], "--help") == 0)
			return (1);
		if (strncmp(av[1], "http://www", 11) != 0)
		{
			printf("Please enter your host with http://www.[host]\n");
			return (2);
		}
	}
	if (ac != 3)
		return (1);
	return (0);
}

int				main(int ac, char **av)
{
	int		err;
	int		usage;

	usage = ft_usage(ac, av);
	if (usage == 1)
	{
		printf("usage: ./proxy [http://[host]] [page]\n");
		return (0);
	}
	else if (usage == 2)
		return (0);
	err = proxy(av);
	if (err == 1)
		printf("Erreur: socket failled\n");
	if (err == 2)
		printf("Erreur: bind failled\n");
	if (err == 3)
		printf("Erreur: connection failled\n");
	if (err == 4)
		printf("Une erreur c'est produite\n");
	return (0);
}
