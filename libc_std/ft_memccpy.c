#include "libft.h"

void    *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	if (dst != NULL && src != NULL)
	{
		ss1 = (unsigned char *)dst;
		ss2 = (unsigned char *)src;
		while (n > 0)
		{
			*ss1 = *ss2;
			if (*ss2 == (unsigned char)c)
				return ((void *)(ss1 + 1));
			ss1++;
			ss2++;
			n--;
		}
	}
	return (NULL);
}
