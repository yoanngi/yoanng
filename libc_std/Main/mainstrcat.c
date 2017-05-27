#include <stdio.h>
#include <string.h>

char *ft_strncat(char *dest, const char *src, size_t n)
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

int main ()
{
   char src[50], dest[50];
   char src2[50], dest2[50];

   strcpy(src,  "This is source");
   strcpy(dest, "This is destination");
   strcpy(src2, "This is source");
   strcpy(dest2, "This is destination");

   strncat(dest, src, -1);
   ft_strncat(dest2, src2, -1);

   printf("Final destination string : |%s|\n", dest);
   printf("*************************************\n");
   printf("strncat perso : |%s|\n", dest2);
   printf("*************************************\n");

   return(0);
}
