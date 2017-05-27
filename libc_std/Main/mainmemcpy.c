//#include "libft.h"
#include <stdio.h>
#include <string.h>

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    char*pdst;
    const char*psrc;

    pdst = (char *)dst;
    psrc = (const char *)src;
    while (n--)
        *pdst++ = *psrc++;
    return (dst);
}

int main ()
{
    const char src[50] = "http://www.tutorialspoint.com";
    char dest[50] = "";
    char dest2[50] = "";

    printf("Before memcpy dest = %s\n", dest);
    memcpy(dest, src, strlen(src)+1);
    printf("After memcpy dest = %s\n", dest);    
    printf("******************************\n");
    printf("Before memcpy dest = %s\n", dest2);
    ft_memcpy(dest2, src, strlen(src)+1);
    printf("After memcpy dest = %s\n", dest2);
    return(0);
}
