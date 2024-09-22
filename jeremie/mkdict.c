/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkdict.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:44:39 by jpiscice          #+#    #+#             */
/*   Updated: 2024/09/22 18:05:40 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	ft_strlen(char *str, int *keylen, int *vallen)
{
	int	len;

	len = 0;
	while (str[len] != ':' && str[len] != '\n' && str[len])
		len++;
	*keylen = len;
	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	*vallen = len;
}

void	ft_split(char *charkey, char *value, char *line)
{
	int	i;

	i = 0;
	while (*line && *line != ':' && *line != '\n')
	{
		charkey[i] = *line;
		line++;
	}
	if (*line == ':')
		line++;
	while (*line <= 32 || *line == 127)
		line++;
	i = 0;
	while (*line && *line != '\n')
	{
		value[i] = *line;
		line++;
	}
}

void	new_entry(t_dict *dict, char *line)
{
	t_entry *entry;
	int		keylen;
	int		vallen;

	ft_strlen(line, &keylen, &vallen);
	entry = *malloc(sizeof(t_entry *));
	if (!dict || !entry)
		return (NULL);
	entry.charkey = malloc((keylen + 1) * sizeof(char));
	entry.value = malloc((vallen + 1) * sizeof(char));
	ft_split(line, charkey, value)
	entry->key = atol(key);
	entry->next = NULL;
	entry->next = dict->last
	dict->size++;
	if (dict->first)
	{
		dict->last->next = entry;
		dict->lasr = entry;
	}
	else
	{
		dict->first = entry;
		dict->last = entry;
	}
}

t_dict	init_list(void)
{
	t_dict	*dict;
	t_entry	*entry;

	dict = malloc(sizeof(dict *);
	entry = malloc(sizeof(entry *);
	if (!dict || !entry)
		return (NULL);
	dict->first = NULL;
	dict->last = NULL;
	dict->size = 0;
	return (dict);
}
