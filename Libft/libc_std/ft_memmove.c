//#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void    *ft_memmove(void *str1, const void *str2, size_t n)
{
    void *buf;

    buf = (void *)malloc(n * sizeof(void*));
    if (!buf)
        return (NULL);
    ft_memcpy(buf, str2, n);
    ft_memcpy(str1, buf, n);
    free(buf);
    return (str1);
}
