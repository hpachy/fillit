/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:10:37 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/30 12:53:28 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_binary(unsigned int tab[32])
{
	unsigned	int	to_print;
	int				i;
	int				decalage;

	i = 0;
	while (i < 32)
	{
		to_print = tab[i];
		decalage = 0;
		while (decalage < 32)
		{
			if (((to_print << decalage) & 0x80000000) == 0x80000000)
				write(1, "1", 1);
			else
				write(1, "0", 1);
			decalage++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	fill_printer_w_tetris(t_data *data, char **printer, int size)
{
	int		no_tetri;
	int		i;
	int		j;

	no_tetri = 1;
	while (no_tetri <= data->nb_tetri)
	{
		j = 0;
		while (j < size)
		{
			i = 0;
			while (i < size)
			{
				if (bit_is_1(TETRI(no_tetri).tab_tetri[j], i))
					printer[i][j] = TETRI(no_tetri).letter;
				i++;
			}
			j++;
		}
		no_tetri++;
	}
}

void	fill_printer_w_zeros(t_data *data, char **printer, int size)
{
	int	i;
	int j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (!bit_is_1((data->board)[j], i))
				printer[i][j] = '.';
			i++;
		}
		j++;
	}
}

void	print_final(char **printer, int size)
{
	int i;
	int j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			write(1, &printer[i][j], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

void	printing(t_data *data, int size)
{
	char	**printer;
	int		i;

	i = 0;
	if ((printer = (char **)malloc(sizeof(*printer) * size)))
	{
		while (i < size)
		{
			if (!(printer[i] = (char *)malloc(sizeof(char) * size)))
				return ;
			i++;
		}
		fill_printer_w_tetris(data, printer, size);
		fill_printer_w_zeros(data, printer, size);
		print_final(printer, size);
	}
}
