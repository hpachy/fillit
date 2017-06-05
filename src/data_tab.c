/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:09:28 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/18 10:09:29 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ccleaner_tab(unsigned int tab[32])
{
	int up;

	up = 0;
	while (up < 32)
	{
		tab[up] = 0;
		up++;
	}
}

void	ccleaner_t_data(t_data *data)
{
	int i;

	i = 0;
	data->nb_tetri = 0;
	ccleaner_tab(data->board);
	while (i < 27)
	{
		ccleaner_tab((data->tetriminos)[i].tab_tetri);
		((data->tetriminos)[i].letter) = '\0';
		i++;
	}
}

int		tab_overflow(unsigned int tab_tetri[32], int size)
{
	int		empty_lines_right;
	int		empty_lines_bottom;

	empty_lines_right = count_empty_lines_x(tab_tetri, 32, 1);
	empty_lines_bottom = count_empty_lines_y(tab_tetri, 32, 1);
	if (empty_lines_right < 32 - size || empty_lines_bottom < 32 - size)
		return (1);
	else
		return (0);
}

int		count_empty_lines_x(unsigned int tab[32], int size, int direct)
{
	int i;
	int j;
	int	count_lines;

	count_lines = 0;
	i = (direct < 0 ? -1 : size);
	while ((direct < 0) ? (++i < size) : (--i >= 0))
	{
		j = -1;
		while (++j < size)
			if (bit_is_1(tab[j], i))
				return (count_lines);
		count_lines++;
	}
	return (count_lines);
}

int		count_empty_lines_y(unsigned int tab[32], int size, int direct)
{
	int j;
	int count_lines;

	count_lines = 0;
	j = (direct < 0 ? -1 : size);
	while ((direct < 0) ? (++j < size) : (--j >= 0))
	{
		if (tab[j] != 0)
			return (count_lines);
		count_lines++;
	}
	return (count_lines);
}
