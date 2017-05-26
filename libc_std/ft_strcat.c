#include "libft.h"

char  *strcat(char *dest, const char *src)
{
  char	*new_str;

	new_str = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (new_str);
}
