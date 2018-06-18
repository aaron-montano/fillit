/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 20:07:48 by amontano          #+#    #+#             */
/*   Updated: 2018/05/25 20:40:30 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_etris
{
	char			*str;
	char			symbol;
	struct s_etris	*next;
	struct s_etris	*prev;
}					t_etris;

t_etris				*create_mino(char *str);
void				append_mino(t_etris *head, char *str);
void				dispose(t_etris *head);
int					count_minos(t_etris *head);
void				assign_data(t_etris *head);

t_etris				*populate_list(char **arg);

char				*ft_strdup(const char *s1);
int					ft_strlen(const char *str);

void				shift_up(char *str);
void				shift_left(char *str);
int					top_row_is_empty(const char *str);
int					left_col_is_empty(const char *str);
void				remove_newline(char *str);

void				solver(t_etris *head);
int					solve_map(t_etris *cursor, char *map, int j, int size);
void				undo(t_etris *cursor, char *map, int size);
void				place_mino(t_etris *cursor, char *map, int j, int size);
int					mino_fits(char *str, char *map, int j, int size);

int					next_block(char *str, int i);
int					col_shift(int i, int next_block);
int					row_shift(int i, int next_block);
void				get_shifts(const char *str, const int i, int nextblock);

void				print_map(const char *str);

char				*spawn_map(void);
void				zero_map(char *map, int size);
void				destroy_map(char *map);
int					get_size(const char *map);
int					get_start_size(t_etris *head);
#endif
