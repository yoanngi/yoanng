#include "libft.h"

char *strncat(char *dest, const char *src, size_t n)
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
