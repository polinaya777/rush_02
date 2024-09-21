/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:58:44 by jpiscice          #+#    #+#             */
/*   Updated: 2024/09/21 23:52:03 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h" 

int	is_sep(char c, char *charset, int space)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i] || (space && ((c >= 9 && c <= 13) || c == ' ')))
			return (1);
		i++;
	}
	return (0);
}

int	csep(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset, 0))
		{
			count++;
			while (is_sep(str[i], charset, 1))
				i++;
		}
		i++;
	}
	count++;
	return (count);
}

char	*ft_strcpy(char *dest, char *src, char *charset, int *steps)
{
	int	i;

	*steps = 0;
	i = 0;
	while (!is_sep(src[*steps], charset, 0) && src[*steps])
		*steps += 1;
	dest = (char *)malloc((*steps + 1) * sizeof(char));
	while (i < *steps)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**split_str;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = csep(str, charset);
	split_str = (char **)malloc((count + 1) * sizeof(char *));
	if (!split_str)
		return (NULL);
	else
	{
		while (*str && i < count)
		{
			while (is_sep(*str, charset, 1) && *str)
				str++;
			split_str[i] = ft_strcpy(split_str[i], str, charset, &j);
			str += j;
			i++;
		}
		split_str[i] = NULL;
	}
	return (split_str);
}
