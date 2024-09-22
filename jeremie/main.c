/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:52:20 by jpiscice          #+#    #+#             */
/*   Updated: 2024/09/22 14:43:58 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int	main(void)
{
	char	*dict;
	char	*tmp;
	int		n_lines;
	t_dict	*list;
	t_entry	*entry;

	dict = "numbers.dict";
	tmp = "tmp.dict";
	n_lines = cleanfile(dict, tmp);
	list = (t_list)malloc(sizeof(t_list));
	if (!list)
	{
		ft_putstr(ERROR);
		return (1);
	}
	entry = NULL;
	return (0);
}
