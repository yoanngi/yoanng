#include "libft.h"

char    *ft_strncat(char *dest, const char *src, size_t n)
{
	while (*dest)
		dest++;
	while (*src)
	{
        if (n == 0)
            break;
		*dest = *src;
		dest++;
		src++;
        n--;
	}
	*dest = '\0';
	return (dest);
}
