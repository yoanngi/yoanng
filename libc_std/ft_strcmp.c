#include "libft.h"

int   ft_strcmp(const char *str1, const char *str2)
{
  if ((*str1 == '\0' && *str2 != '\0') || (*str1 != '\0' && *str2 == '\0'))
		return (1);
	while (*str1 && *str2 && (*s1 == *s2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
