/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:09:14 by mael-faq          #+#    #+#             */
/*   Updated: 2024/09/22 17:09:15 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*get_nbr(int file)
{
	int	i;
	char	buffer[1];
	char	*str;

	str = (char *) malloc(sizeof(char) * 128);
	if (str == NULL)
		return (NULL);
	read(file, buffer, 1);
	while (buffer[0] == '\n')
		read(file, buffer, 1);
	
	i = 0;
	while (buffer[0] >= '0' && buffer[0] <= '9')
	{
		str[i] = buffer[0];
		read(file, buffer, 1);
		i++;
	}
	return (str);
}

char	*get_number_name(int file, char *buffer)
{
	int	i;
	char	*str;
	str = (char *) malloc(sizeof(char) * 128);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (buffer[0] != '\n')
	{
		str[i] = buffer[0];
		read(file, buffer, 1);
		i++;
	}
	return (str);
}

t_list	*init_list(char *file_name)
{
	int	i;
	int	file;
	char	buffer[1];
	t_list	*list;
	char *tmp;

	file = open(file_name, O_RDONLY);
	list = (t_list *)malloc(sizeof(t_list) * 33);
	if (file == -1 || list == NULL)
		return (NULL);
	i = 0;
	while (i < 32)
	{
		list[i].nbr = ft_atoi(get_nbr(file));
		read(file, buffer, 1);
		while (buffer[0] == ' ')
			read(file, buffer, 1);
		if (buffer[0] == ':')
			read(file, buffer, 1);
		while (buffer[0] == ' ')
			read(file, buffer, 1);
		tmp = get_number_name(file, buffer);
		list[i].number_name = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	close(file);
	return (list);
}