#include "libft.h"

void    *ft_memchr(const void *str, int c, size_t n)
{
    while (n--)
    {
        if (*(unsigned char *)str != (unsigned char)c)
            ++str;
        else
            return ((void *)str);
    }
    return (NULL);
}
