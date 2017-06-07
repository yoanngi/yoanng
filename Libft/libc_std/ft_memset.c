/* Header
ft_memeset > OK */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char *chaine;
	size_t i;

	i = 0;
	if (n > 0)
	{
		char *chaine = str;
		while (n > 0)
		{
			*chaine[i] = c;
			i++;
			n--;
		}
	}
	return (str);
}
