#include "libft.h"

int   ft_isalnum(int c)
{
  if ((c >= 'a' && c <= 'z') ||(c >= 'A' && c <= 'Z'))
    return (c);
  else if (c >= '0' && c <= '9')
    return (c);
  else
    return (0);
}
