#include "libft.h"

int   ft_strncmp(const char *str1, const char *str2, size_t n)
{
  size_t i;

  i = 0;
  if ((*str1 == '\0' && *str2 != '\0') || (*str1 != '\0' && *str2 == '\0'))
		return (1);
  else if (n == 0)
    return (0);
  else
    while ((str1[i] != '\0') && (str2[i] != '\0') && (str1[i] == str2[i]) && (i < n) && (i != n - 1))
    {
      i++;
    }
    return (str1[i] - str2[i]);
}
