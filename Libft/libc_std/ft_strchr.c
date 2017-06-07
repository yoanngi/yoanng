#include "libft.h"

char  *ft_strchr(const char *str, int c)
{
  while (1)
	{
    if (*str == c)
			return ((char *)str);
		else if (*str++ == '\0')
			return (NULL);
	}
}
