#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*new;
	size_t	i;
	size_t	len_str;

	if (str == NULL)
		return (NULL);
	len_str = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * (len_str + 1));
	if (new != NULL)
	{
		i = 0;
		while ((str[i] != '\0') && (i < len_str))
		{
			new[i] = str[i];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
