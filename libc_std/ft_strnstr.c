#include "libft.h"

char   *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i2;
	size_t	c;

	i = 0;
	i2 = 0;
	c = 0;
	while ((haystack[i] != '\0') && (needle[i2] != '\0') && (i < len))
	{
		if (haystack[i] == needle[i2])
			i2++;
		i++;
	}
	if (i2 == ft_strlen(needle))
	{
		while (c < (i - i2))
		{
			haystack++;
			c++;
		}
		return (char *)haystack;
	}
	else
		return (NULL);
}
