#include "libft.h"

size_t    ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t    s;

    s = size;
    while (*dst && s > 0 && s--)
         dst++;
    while (*src && s > 1 && s--)
    {
        *dst++ = *src++;
        if (s == 1)
            *dst = '\0';
    }
    return (size - s);
}
