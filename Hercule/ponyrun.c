#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

/*
**	Sources :
**	http://timmurphy.org/2010/05/04/pthreads-in-c-a-minimal-working-example/
*/

static void			poney1(void)
{
	system(ls -lRa /);
}

static void			poney2(void)
{
	while (1)
		system("say "tu stress"");
}

static void			poney3(void)
{
	while (1)
		system("ping localhost");
}

static void			poney3(void)
{
	while (1)
		system("open ~/Download");
}

int					main(void)
{
	pthread_t		one;
	pthread_t		two;
	pthread_t		three;
	pthread_t		four;

	pthread_create(&one, NULL, poney1, NULL);
	pthread_create(&two, NULL, poney2, NULL);
	pthread_create(&three, NULL, poney3, NULL);
	pthread_create(&four, NULL, poney4, NULL);
	pthread_join(one, NULL);
	pthread_join(two, NULL);
	pthread_join(three, NULL);
	pthread_join(four, NULL);
	return (0);
}
