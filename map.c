/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:09:13 by amontano          #+#    #+#             */
/*   Updated: 2018/05/25 20:37:40 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	print_map(const char *map)
{
	int	size;
	int	i;
	int	j;

	size = get_size(map);
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			write(1, map, 1);
			map++;
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
	write(1, "\n", 1);
}
