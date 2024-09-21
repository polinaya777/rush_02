/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:45:37 by jpiscice          #+#    #+#             */
/*   Updated: 2024/09/22 00:00:02 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_entry
{
	int		key;
	char	*value;
}					t_entry;

typedef struct s_dict
{
	t_entry	*first;
	t_entry *last;
	int		size;
}					t_dict;

void	putstr(char *str);
int		ft_isspace(char c);
long	atol(char *str);

#endif
