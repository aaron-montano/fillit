/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_etris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 03:42:37 by amontano          #+#    #+#             */
/*   Updated: 2018/05/25 20:37:57 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		top_row_is_empty(const char *str)
{
	if (str[0] == '.' && str[1] == '.' && str[2] == '.' && str[3] == '.')
		return (1);
	else
		return (0);
}

int		left_col_is_empty(const char *str)
{
	if (str[0] == '.' && str[5] == '.' && str[10] == '.' && str[15] == '.')
		return (1);
	else
		return (0);
}

void	shift_up(char *str)
{
	char	tmp;
	int		i;

	i = 0;
	while (i < 4)
	{
		tmp = str[i];
		str[i] = str[i + 5];
		str[i + 5] = str[i + 10];
		str[i + 10] = str[i + 15];
		str[i + 15] = tmp;
		i++;
	}
}

void	shift_left(char *str)
{
	char	tmp;
	int		i;

	i = 0;
	while (i / 5 < 4)
	{
		tmp = str[i];
		str[i] = str[i + 1];
		str[i + 1] = str[i + 2];
		str[i + 2] = str[i + 3];
		str[i + 3] = tmp;
		i += 5;
	}
}

void	remove_newline(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			j = i;
			while (str[j])
			{
				str[j] = str[j + 1];
				j++;
			}
		}
		i++;
	}
	str[16] = '\0';
	str[17] = '\0';
	str[18] = '\0';
	str[19] = '\0';
}
