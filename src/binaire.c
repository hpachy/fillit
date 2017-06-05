/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaire.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:09:08 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/18 10:09:10 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_bit_1(unsigned int *line, int position)
{
	unsigned int hexa;

	hexa = 0x80000000;
	hexa = hexa >> position;
	*line = *line | hexa;
}

int		bit_is_1(unsigned int line, int position)
{
	unsigned int hexa;

	hexa = 0x80000000;
	if (((hexa >> position) & line) == (hexa >> position))
		return (1);
	else
		return (0);
}

void	convert_block_to_binaire(t_data *data, char (*buffer)[21])
{
	int i;
	int j;
	int up;

	up = -1;
	j = 0;
	i = 0;
	while (++up < 20)
	{
		if ((*buffer)[up] == '#')
			set_bit_1(&(TETRI(data->nb_tetri).tab_tetri[j]), i);
		else if ((*buffer)[up] == '\n')
		{
			i = -1;
			j++;
		}
		i++;
	}
}
