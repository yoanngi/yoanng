//#include "libft.h"
#include <stdio.h>
#include <string.h>

void    *ft_memmove(void *str1, const void *str2, size_t n)
{
    size_t i;

    i = 0;
    while (n > 0)
    {
        if (n == 0)
            break;
        str1[i] == str2[i];
        i++;
        n--;
    }
}

int main ()
{
    char dest[] = "oldstring";
    const char src[]  = "newstring";
    char dest2[] = "oldstring";
    const char src2[]  = "newstring";


    printf("Before memmove dest = %s, src = %s\n", dest, src);
    memmove(dest, src, 9);
    printf("After memmove dest = %s, src = %s\n", dest, src);
    printf("*************************************************\n");
    printf("Before memmove dest = %s, src = %s\n", dest2, src2);
    ft_memmove(dest2, src2, 9);
    printf("After memmove dest = %s, src = %s\n", dest2, src2);
    return(0);
}
