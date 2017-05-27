#include <stdio.h>
#include <string.h>

//size_t  ft_strlcat(char *dst, const char *src, size_t size)
//{
    
//}
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

int main ()
{
    char src[50], dest[50];
    char src2[50], dest2[50];
    size_t i;
    size_t j;

   strcpy(src,  "This is source et alors");
   strcpy(dest, "This is destination la");
   strcpy(src2, "This is source et alors");
   strcpy(dest2, "This is destination la");

   i = strlcat(dest, src, 1);
   j = ft_strlcat(dest2, src2, 1);

   printf("Final destination string : |%s|\n", dest);
   printf("%zu\n", i);
   printf("*************************************\n");
   printf("strncat perso : |%s|\n", dest2);
   printf("%zu\n", i);
   printf("*************************************\n");

   return(0);
}
