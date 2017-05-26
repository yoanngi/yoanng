#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int i;
	int b;

	i = 0;
	b = 0;
	if (n <= 0)
		return;
	while (n > i)
	{
		*s[b] == 0;
		n--;
		b++;
	}
}
