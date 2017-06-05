/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:10:26 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/18 10:10:27 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_y(unsigned int tab[32], int jump_y)
{
	int i;
	int up;

	if (jump_y < 0)
		i = 31 + jump_y;
	else
		i = 31 - jump_y;
	while (++i != 32)
	{
		if (jump_y < 0)
		{
			up = -1;
			while (++up != 31)
				tab[up] = tab[up + 1];
			tab[31] = 0;
		}
		if (jump_y > 0)
		{
			up = 32;
			while (--up != 0)
				tab[up] = tab[up - 1];
			tab[0] = 0;
		}
		(jump_y < 0 ? jump_y++ : jump_y--);
	}
}

void	move_x(unsigned int tab[32], int index_x)
{
	int i;

	i = 0;
	while (i < 32)
	{
		if (index_x > 0)
			tab[i] = tab[i] >> index_x;
		if (index_x < 0)
			tab[i] = tab[i] << -index_x;
		i++;
	}
}

int		get_next_position(unsigned int tab[32], int size)
{
	if (count_empty_lines_x(tab, size, 1) > 0)
	{
		move_x(tab, 1);
		return (1);
	}
	else if (count_empty_lines_y(tab, size, 1) > 0)
	{
		move_y(tab, 1);
		move_x(tab, -count_empty_lines_x(tab, size, -1));
		return (1);
	}
	else
		return (0);
}

int		get_last_position(unsigned int tab[32], int size)
{
	if (count_empty_lines_x(tab, size, -1) > 0)
	{
		move_x(tab, -1);
		return (1);
	}
	else if (count_empty_lines_y(tab, size, -1) > 0)
	{
		move_y(tab, -1);
		move_x(tab, count_empty_lines_x(tab, size, 1));
		return (1);
	}
	else
		return (0);
}

void	push_corner(unsigned int tab[32], int size)
{
	int	empty_lines_left;
	int	empty_lines_top;

	empty_lines_left = count_empty_lines_x(tab, size, -1);
	empty_lines_top = count_empty_lines_y(tab, size, -1);
	move_x(tab, -empty_lines_left);
	move_y(tab, -empty_lines_top);
}
