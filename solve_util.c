/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:27:11 by amontano          #+#    #+#             */
/*   Updated: 2018/05/25 20:38:20 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	next_block(char *str, int i)
{
	if (str[i] && str[i] == '#')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			return (i);
		i++;
	}
	return (-1);
}

int	col_shift(int i, int next_block)
{
	int colshift;

	if (next_block < 0)
		return (0);
	colshift = (next_block % 4) - (i % 4);
	return (colshift);
}

int	row_shift(int i, int next_block)
{
	int	rowshift;

	if (next_block < 0)
		return (0);
	rowshift = (next_block / 4) - (i / 4);
	return (rowshift);
}
