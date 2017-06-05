/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:09:37 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/18 10:09:39 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	create_catalogue1(unsigned int catalogue[19][4])
{
	catalogue[0][0] = 0x80000000;
	catalogue[0][1] = 0xc0000000;
	catalogue[0][2] = 0x40000000;
	catalogue[0][3] = 0x0;
	catalogue[1][0] = 0x60000000;
	catalogue[1][1] = 0xc0000000;
	catalogue[1][2] = 0x0;
	catalogue[1][3] = 0x0;
	catalogue[2][0] = 0x40000000;
	catalogue[2][1] = 0xc0000000;
	catalogue[2][2] = 0x80000000;
	catalogue[2][3] = 0x0;
	catalogue[3][0] = 0xc0000000;
	catalogue[3][1] = 0x60000000;
	catalogue[3][2] = 0x0;
	catalogue[3][3] = 0x0;
	catalogue[4][0] = 0xc0000000;
	catalogue[4][1] = 0xc0000000;
	catalogue[4][2] = 0x0;
	catalogue[4][3] = 0x0;
	catalogue[5][0] = 0xf0000000;
	catalogue[5][1] = 0x0;
	catalogue[5][2] = 0x0;
	catalogue[5][3] = 0x0;
}

void	create_catalogue2(unsigned int catalogue[19][4])
{
	catalogue[6][0] = 0x80000000;
	catalogue[6][1] = 0x80000000;
	catalogue[6][2] = 0x80000000;
	catalogue[6][3] = 0x80000000;
	catalogue[7][0] = 0xe0000000;
	catalogue[7][1] = 0x40000000;
	catalogue[7][2] = 0x0;
	catalogue[7][3] = 0x0;
	catalogue[8][0] = 0x40000000;
	catalogue[8][1] = 0xe0000000;
	catalogue[8][2] = 0x0;
	catalogue[8][3] = 0x0;
	catalogue[9][0] = 0x80000000;
	catalogue[9][1] = 0xc0000000;
	catalogue[9][2] = 0x80000000;
	catalogue[9][3] = 0x0;
	catalogue[10][0] = 0x40000000;
	catalogue[10][1] = 0xc0000000;
	catalogue[10][2] = 0x40000000;
	catalogue[10][3] = 0x0;
	catalogue[11][0] = 0xe0000000;
	catalogue[11][1] = 0x80000000;
	catalogue[11][2] = 0x0;
	catalogue[11][3] = 0x0;
}

void	create_catalogue3(unsigned int catalogue[19][4])
{
	catalogue[12][0] = 0xc0000000;
	catalogue[12][1] = 0x40000000;
	catalogue[12][2] = 0x40000000;
	catalogue[12][3] = 0x0;
	catalogue[13][0] = 0x20000000;
	catalogue[13][1] = 0xe0000000;
	catalogue[13][2] = 0x0;
	catalogue[13][3] = 0x0;
	catalogue[14][0] = 0x80000000;
	catalogue[14][1] = 0x80000000;
	catalogue[14][2] = 0xc0000000;
	catalogue[14][3] = 0x0;
	catalogue[15][0] = 0xe0000000;
	catalogue[15][1] = 0x20000000;
	catalogue[15][2] = 0x0;
	catalogue[15][3] = 0x0;
	catalogue[16][0] = 0x40000000;
	catalogue[16][1] = 0x40000000;
	catalogue[16][2] = 0xc0000000;
	catalogue[16][3] = 0x0;
	catalogue[17][0] = 0x80000000;
	catalogue[17][1] = 0xe0000000;
	catalogue[17][2] = 0x0;
	catalogue[17][3] = 0x0;
}

void	create_catalogue4(unsigned int catalogue[19][4])
{
	catalogue[18][0] = 0xc0000000;
	catalogue[18][1] = 0x80000000;
	catalogue[18][2] = 0x80000000;
	catalogue[18][3] = 0x0;
}

int		tetri_or_not_tetri(unsigned int tab[32])
{
	unsigned int	catalogue[19][4];
	int				i_catalogue;
	int				count_equ_lines;
	int				i_lines;

	create_catalogue1(catalogue);
	create_catalogue2(catalogue);
	create_catalogue3(catalogue);
	create_catalogue4(catalogue);
	i_catalogue = 0;
	while (i_catalogue < 19)
	{
		i_lines = 0;
		count_equ_lines = 0;
		while (i_lines < 4)
		{
			if (catalogue[i_catalogue][i_lines] == tab[i_lines])
				count_equ_lines++;
			i_lines++;
		}
		if (count_equ_lines == 4)
			return (1);
		i_catalogue++;
	}
	return (0);
}
