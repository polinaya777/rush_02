/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 08:33:23 by jpiscice          #+#    #+#             */
/*   Updated: 2024/09/22 14:43:16 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int	len_dict(char *dict)
{
	char	buffer[1024];
	int		size;
	int		bytes;
	int		fd;

	fd = open(dict, O_RDONLY);
	size = 0;
	bytes = read(fd, buffer, 1);
	while (bytes > 0)
	{
		size += bytes;
		bytes = read(fd, buffer, 1);
	}
	close(fd);
	return (size);
}

int	clean_buffer(char *buffer)
{
	int	i;
	int	count_nl;

	i = 0;
	count_nl = 0;
	while (buffer[i])
	{
		while (buffer[i] && (buffer[i] <= 32 || buffer[i] == 127))
			i++;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		count_nl++;
		while (i >= 0 && (buffer[i - 1] <= 32 || buffer[i - 1] == 127))
		{
			buffer[i - 1] = '\n';
			i--;
		}
		i++;
	}
	return (count_nl);
}

void	clean_dict(char *tmpdict, char *buffer)
{
	int		i;
	int		fd_tmp;

	fd_tmp = open(tmpdict, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	i = 0;
	while (buffer[i])
	{
		while (buffer[i] && (buffer[i] <= 32 || buffer[i] == 127))
			i++;
		while (buffer[i] && buffer[i] != '\n')
		{
			write(fd_tmp, &buffer[i], 1);
			i++;
		}
		if (buffer[i] == '\0')
			buffer[i + 1] = '\0';
		write(fd_tmp, &buffer[i], 1);
		i++;
	}
	close(fd_tmp);
}

int	cleanfile(char *dict, char *tmp)
{
	int		n_lines;
	int		fd_dict;
	char	buffer[1024];

	fd_dict = open(dict, O_RDONLY);
	read(fd_dict, buffer, len_dict(dict));
	close(fd_dict);
	n_lines = clean_buffer(buffer);
	clean_dict(tmp, buffer);
	return (n_lines);
}
