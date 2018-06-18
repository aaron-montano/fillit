/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:02:22 by amontano          #+#    #+#             */
/*   Updated: 2018/05/25 20:38:18 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	solver(t_etris *head)
{
	char	*map;
	int		map_size;

	map = spawn_map();
	map_size = get_start_size(head);
	zero_map(map, map_size);
	while (solve_map(head, map, 0, map_size) == 0)
	{
		map_size++;
		zero_map(map, map_size);
	}
	print_map(map);
}

int		solve_map(t_etris *cursor, char *map, int j, int size)
{
	while (map[j])
	{
		if (mino_fits(cursor->str, map, j, size) == 1)
		{
			place_mino(cursor, map, j, size);
			if (!cursor->next || solve_map(cursor->next, map, 0, size) == 1)
				return (1);
			else
				undo(cursor, map, size);
		}
		j++;
	}
	return (0);
}

int		mino_fits(char *str, char *map, int j, int size)
{
	int	nextblock;
	int colshift;
	int	rowshift;
	int	i;

	i = 0;
	while (str[i] && str[i] == '.')
		i++;
	nextblock = i;
	while (nextblock >= 0)
	{
		if (map[j] != '.' && str[i] == '#')
			return (0);
		nextblock = next_block(str, i);
		rowshift = row_shift(i, nextblock);
		colshift = col_shift(i, nextblock);
		if (j + colshift + rowshift * size >= ft_strlen(map) || \
			(colshift > 0 && ((j % (size)) + colshift > size - 1)) || \
			((colshift < 0) && ((j % size) + colshift < 0)) || \
			(rowshift > 0 && ((j / size) + rowshift > size - 1)))
			return (0);
		i = nextblock;
		j += (colshift) + (rowshift * size);
	}
	return (1);
}

void	place_mino(t_etris *cursor, char *map, int j, int size)
{
	int	nextblock;
	int	colshift;
	int	rowshift;
	int	current;

	current = 0;
	while (cursor->str[current] == '.')
		current++;
	nextblock = current;
	while (nextblock >= 0)
	{
		if (map[j] == '.' && cursor->str[current] == '#')
			map[j] = cursor->symbol;
		nextblock = next_block(cursor->str, current);
		rowshift = row_shift(current, nextblock);
		colshift = col_shift(current, nextblock);
		current = nextblock;
		j += (colshift) + (rowshift * size);
	}
}

void	undo(t_etris *cursor, char *map, int size)
{
	int	nextblock;
	int	colshift;
	int	rowshift;
	int	current;
	int	j;

	j = 0;
	current = 0;
	while (map[j] != cursor->symbol)
		j++;
	while (cursor->str[current] == '.')
		current++;
	nextblock = current;
	while (nextblock >= 0)
	{
		if (map[j] == cursor->symbol && cursor->str[current] == '#')
			map[j] = '.';
		nextblock = next_block(cursor->str, current);
		rowshift = row_shift(current, nextblock);
		colshift = col_shift(current, nextblock);
		current = nextblock;
		j += (colshift) + (rowshift * size);
	}
}
