/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 08:41:30 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/15 12:41:12 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		if ((str[i] >= 97 && str[i] <= 122) &&
	!(str[i - 1] >= 48 && str[i - 1] <= 57))
		{
			str[i] = str[i] - 32;
			i++;
			while (str[i] >= 97 && str[i] <= 122)
				i++;
		}
		if (str[i] >= 48 && str[i] <= 57)
		{
			while ((str[i] >= 48 && str[i] <= 57) ||
	(str[i] >= 97 && str[i] <= 122))
				i++;
		}
		i++;
	}
	return (str);
}
