/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_etris.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:21:11 by amontano          #+#    #+#             */
/*   Updated: 2018/05/25 20:38:29 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_etris	*create_mino(char *str)
{
	t_etris *new_mino;

	new_mino = (t_etris *)malloc(sizeof(t_etris));
	if (!new_mino)
		return (NULL);
	if (str == NULL)
		new_mino->str = NULL;
	else
	{
		new_mino->str = ft_strdup(str);
		if (new_mino->str == NULL)
			return (NULL);
	}
	new_mino->next = NULL;
	new_mino->prev = NULL;
	return (new_mino);
}

void	append_mino(t_etris *head, char *str)
{
	t_etris *cursor;
	t_etris *new_mino;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	new_mino = create_mino(str);
	cursor->next = new_mino;
}

void	dispose(t_etris *head)
{
	t_etris *cursor;
	t_etris *tmp;

	if (head)
	{
		cursor = head->next;
		free(head->str);
		head->next = NULL;
		head->prev = NULL;
		while (cursor)
		{
			cursor->prev = NULL;
			tmp = cursor->next;
			free(cursor->str);
			free(cursor);
			cursor = tmp;
		}
	}
}

int		count_minos(t_etris *head)
{
	t_etris	*cursor;
	int		i;

	i = 0;
	cursor = head;
	while (cursor != NULL)
	{
		i++;
		cursor = cursor->next;
	}
	return (i);
}

void	assign_data(t_etris *head)
{
	t_etris	*cursor;
	char	symbol;

	symbol = 65;
	cursor = head;
	while (cursor != NULL)
	{
		cursor->symbol = symbol++;
		if (cursor->next != NULL)
			(cursor->next)->prev = cursor;
		cursor = cursor->next;
	}
}
