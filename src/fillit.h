/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:09:47 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/18 10:09:48 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# define TETRI(rank)	((data->tetriminos)[rank])

typedef struct		s_tetri
{
	unsigned int	tab_tetri[32];
	char			letter;
}					t_tetri;

typedef struct		s_data
{
	int				nb_tetri;
	unsigned int	board[32];
	t_tetri			tetriminos[27];
}					t_data;

void				ccleaner_tab(unsigned int tab[32]);
void				ccleaner_t_data(t_data *data);
int					count_empty_lines_x(unsigned int tab[32],
					int size, int direct);
int					count_empty_lines_y(unsigned int tab[32],
					int size, int direct);
int					tab_overflow(unsigned int tab_tetri[32], int size);
int					process_last_block(char (*buffer)[21], t_data *data);
int					reader(char *file, t_data *data);
int					tetri_or_not_tetri(unsigned int tab[32]);
void				convert_block_to_binaire(t_data *data,
					char (*buffer)[21]);
void				set_bit_1(unsigned int *line, int position);
int					bit_is_1(unsigned int line, int position);
void				move_y(unsigned int tab[32], int jump_y);
void				move_x(unsigned int tab[32], int index_x);
int					get_next_position(unsigned int tab[32], int size);
int					get_last_position(unsigned int tab[32], int size);
void				push_corner(unsigned int tab[32], int size);
void				solve(t_data *data);
int					try_to_fit(unsigned int board[32],
					unsigned int tab_tetri[32], int size);
void				print_binary(unsigned int tab[32]);
void				fill_printer_w_tetris(t_data *data, char **printer,
					int size);
void				fill_printer_w_zeros(t_data *data, char **printer,
					int size);
void				print_final(char **printer, int size);
void				printing(t_data *data, int size);
int					checkernorme(char (*buffer)[21]);

#endif
