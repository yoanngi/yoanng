#include "libft.h"

int   ft_isascii(int c)
{
  if (c >= 0 && c <= 177)
    return (c);
  else
    return (0);
}
