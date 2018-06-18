/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:02:18 by amontano          #+#    #+#             */
/*   Updated: 2018/05/25 20:37:37 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	shifter_zerus(t_etris *all_minos)
{
	t_etris *cursor;

	cursor = all_minos;
	while (cursor != NULL)
	{
		while (top_row_is_empty(cursor->str) == 1)
			shift_up(cursor->str);
		while (left_col_is_empty(cursor->str) == 1)
			shift_left(cursor->str);
		remove_newline(cursor->str);
		cursor = cursor->next;
	}
	assign_data(all_minos);
}

int		main(int argc, char **argv)
{
	t_etris	*all_minos;

	if (argc == 2)
	{
		all_minos = populate_list(&argv[1]);
		if (all_minos == NULL || count_minos(all_minos) > 26)
		{
			write(1, "error\n", 6);
			dispose(all_minos);
			exit(0);
		}
		shifter_zerus(all_minos);
		solver(all_minos);
	}
	else
		write(1, "usage: ./fillit valid_file\n", 27);
	exit(0);
}
