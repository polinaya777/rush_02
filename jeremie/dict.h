/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:45:37 by jpiscice          #+#    #+#             */
/*   Updated: 2024/09/22 16:53:22 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define ERROR	"Dict Error\n"

typedef struct s_entry
{
	int		key;
	char	*charkey;
	int		size;
	char	*value;
	t_entry	*next;
	t_entry	*prev;
}					t_entry;

typedef struct s_dict
{
	t_entry	*first;
	t_entry	*last;
	int		size;
}					t_dict;

void				putstr(char *str);
int					ft_isspace(char c);
unsigned long long	atol(const char *str);
int					len_dict(char *dict);
int					clean_buffer(char *buffer);
void				clean_dict(char *tmpdict, char *buffer);

#endif
