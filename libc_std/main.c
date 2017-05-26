#include <stdio.h>
#include <string.h>

char  *strcat(char *dest, const char *src)
{
  
  return ();
}

int main ()
{
   char src[50], dest[50];

   strcpy(src,  "This is source");
   strcpy(dest, "This is destination");

   strcat(dest, src);

   printf("Final destination string : |%s|", dest);

   return(0);
}
