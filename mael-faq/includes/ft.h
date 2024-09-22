/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:09:17 by mael-faq          #+#    #+#             */
/*   Updated: 2024/09/22 20:02:08 by pyarova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct s_list
{
	int		nbr;
	char	*number_name;
}		t_list;

void		ft_putchar(char c);
char		*ft_strdup(char *src);
void		ft_putstr(char *str);
long long	ft_atol(char *str);
char		*get_nbr(int fd);
char		*get_number_name(int fd, char *c);
t_list		*init_list(char *file);

#endif
