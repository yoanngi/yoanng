#include "libft.h"

int ft_isprint(int c)
{
  if(c >= 40 && c <= 176)
    return (c);
  else
    return (0);
}
