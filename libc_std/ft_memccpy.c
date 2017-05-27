#include "libft.h"

void    *ft_memccpy(void *dest, const void *src, int c, size_t n)
{

    // A modifier, incomplet (int c pour les unsigned)
    char*pdst;
    const char*psrc;

    pdst = (char *)dst;
    psrc = (const char *)src;
    while (n--)
        *pdst++ = *psrc++;
    return (dst);
}

int main()
{
    return (0);
}
