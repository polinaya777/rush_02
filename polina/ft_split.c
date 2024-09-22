#include <stdlib.h>

int	ft_is_sep(char c, char *charset, int space)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i] || (space && ((c >= 9 && c <= 13) || c == 32)))
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_sep(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i], charset, 0))
		{
			count++;
			while (str[i] && ft_is_sep(str[i], charset, 1))
				i++;
		}
		else
			i++;
	}
	if (i > 0 && !ft_is_sep(str[i - 1], charset, 0))
		count++;
	return (count);
}

char	*ft_strcpy(char *src, char *charset, int *steps)
{
	int		i;
	char	*dest;

	*steps = 0;
	while (!ft_is_sep(src[*steps], charset, 0) && src[*steps])
		(*steps)++;
	dest = (char *)malloc((*steps + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < *steps)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_free_all(char **split_str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split_str[i]);
		i++;
	}
	free(split_str);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		count;
	char	**split_str;

	count = ft_count_sep(str, charset);
	split_str = (char **)malloc((count + 1) * sizeof(char *));
	if (!split_str)
		return (NULL);
	i = 0;
	while (*str && i < count)
	{
		while (ft_is_sep(*str, charset, 1) && *str)
			str++;
		split_str[i] = ft_strcpy(str, charset, &j);
		if (!split_str[i])
		{
			ft_free_all(split_str, i);
			return (NULL);
		}
		str += j;
		i++;
	}
	split_str[i] = NULL;
	return (split_str);
}
