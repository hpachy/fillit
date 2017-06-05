/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:08:53 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/30 12:51:59 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		try_to_fit(unsigned int board[32], unsigned int tab_tetri[32], int size)
{
	int up;

	if (tab_overflow(tab_tetri, size))
	{
		return (0);
	}
	up = -1;
	while (++up < 32)
	{
		if ((board[up] & tab_tetri[up]) != 0)
			return (0);
	}
	up = -1;
	while (++up < 32)
		board[up] = board[up] | tab_tetri[up];
	return (1);
}

void	remove_tetri(unsigned int board[32], unsigned int tab_tetri[32])
{
	int up;

	up = -1;
	while (++up < 32)
		board[up] = board[up] ^ tab_tetri[up];
}

int		is_solvable(t_data *data, int index_tetri, int tab_size)
{
	int	i;

	i = 0;
	while (get_next_position(TETRI(index_tetri).tab_tetri, tab_size))
	{
		if (i == 0)
		{
			i = 1;
			get_last_position(TETRI(index_tetri).tab_tetri, tab_size);
		}
		if (try_to_fit(data->board, TETRI(index_tetri).tab_tetri, tab_size))
		{
			if (index_tetri == data->nb_tetri)
				return (1);
			if (is_solvable(data, index_tetri + 1, tab_size))
				return (1);
			else
				remove_tetri(data->board, TETRI(index_tetri).tab_tetri);
		}
	}
	push_corner(TETRI(index_tetri).tab_tetri, tab_size);
	return (0);
}

int		ft_sqrt(int input)
{
	int	output;

	if (input < 0)
		return (0);
	output = 0;
	while (output * output < input)
		output++;
	return (output);
}

void	solve(t_data *data)
{
	int		size;

	size = ft_sqrt(data->nb_tetri * 4);
	while (size <= 32)
	{
		if (is_solvable(data, 1, size))
		{
			printing(data, size);
			return ;
		}
		size++;
	}
}
