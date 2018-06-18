/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:38:09 by amontano          #+#    #+#             */
/*   Updated: 2018/05/25 20:37:49 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		get_size(const char *map)
{
	int	area;
	int	pf_sqr;
	int	size;

	area = 0;
	size = 0;
	pf_sqr = 0;
	while (map[area] != '\0')
		area++;
	while (pf_sqr < area)
	{
		pf_sqr += size + size + 1;
		size++;
	}
	return (size);
}

int		get_start_size(t_etris *head)
{
	int	n_minos;
	int	area_tet;
	int	pf_sqr;
	int	size;

	size = 0;
	n_minos = count_minos(head);
	area_tet = n_minos + n_minos + n_minos + n_minos;
	pf_sqr = 0;
	while (pf_sqr < area_tet)
	{
		pf_sqr += size + size + 1;
		size++;
	}
	return (size);
}

char	*spawn_map(void)
{
	char	*map;

	map = (char *)malloc(sizeof(char) * 1024);
	return (map);
}

void	zero_map(char *map, int size)
{
	int		area;
	int		i;

	i = 0;
	area = size * size;
	while (i < area)
		map[i++] = '.';
	map[i] = '\0';
}

void	destroy_map(char *map)
{
	while (*map)
	{
		map = NULL;
		map++;
	}
	free(map);
}
