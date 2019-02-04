/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:10:02 by amontano          #+#    #+#             */
/*   Updated: 2018/05/25 20:38:33 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		valid_connect(const char *str, int i)
{
	int	ncon;

	ncon = 0;
	if (str[i] == '#')
	{
		if (i % 5 == 4)
			return (0);
		if (i / 5 < 3 && str[i + 5] == '#')
			ncon++;
		if (i / 5 > 0 && str[i - 5] == '#')
			ncon++;
		if (i % 5 < 3 && str[i + 1] == '#')
			ncon++;
		if (i % 5 > 0 && str[i - 1] == '#')
			ncon++;
	}
	return (ncon);
}

int		valid_buf(const char *str)
{
	int	i;
	int	nbloc;
	int	nconnect;

	i = 0;
	nbloc = 0;
	nconnect = 0;
	while (i < 20)
	{
		if (i % 5 < 4 && str[i] != '.' && str[i] != '#')
			return (-1);
		if (i % 5 == 4 && str[i] != '\n')
			return (-1);
		if (i % 5 < 4 && str[i] == '#')
		{
			nbloc++;
			nconnect += valid_connect(str, i);
		}
		i++;
	}
	if (nbloc != 4 || (nconnect != 6 && nconnect != 8))
		return (-1);
	return (1);
}

t_etris	*populate_list(char **arg)
{
	int		fd;
	char	buf[20];
	t_etris	*head;

	fd = open(*arg, O_RDONLY);
	if (read(fd, buf, 20) == 20 && valid_buf(buf) == 1)
	{
		head = create_mino(buf);
		if (read(fd, buf, 1) == 0)
			return (head);
	}
	else
		return (NULL);
	while (read(fd, buf, 20) == 20 && valid_buf(buf) == 1)
	{
		append_mino(head, buf);
		if (read(fd, buf, 1) == 0)
			return (head);
	}
	return (NULL);
}
