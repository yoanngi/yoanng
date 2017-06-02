#include "libft.h"

char  *ft_strrchr(const char *str, int c)
{
	char	*last;

	while (1)
	{
		if (*str == c)
			last = (char *)str;
		if (*str++ == '\0')
			return (last);
	}
}
