unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_is_in_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	*ft_strtrim(char *str, char *charset)
{
	unsigned int 	i;
	char			*end;
	char			*res;

	if (!str || !charset)
		return (NULL);
	while (*str && ft_is_in_sep(*str, charset))
		str++;
	if (*str == '\0')
		return (NULL);
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_is_in_sep(*end, charset))
		end--;
	res = (char *)malloc((unsigned int)(end - str + 1 + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < (unsigned int)(end - str + 1 + 1));
	{
		res[i] = str[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}
