/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:10:52 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/18 10:10:57 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		process_block(char (*buffer)[21], t_data *data)
{
	if (!checkernorme(buffer))
		return (0);
	data->nb_tetri++;
	convert_block_to_binaire(data, buffer);
	push_corner(TETRI(data->nb_tetri).tab_tetri, 4);
	if (tetri_or_not_tetri(TETRI(data->nb_tetri).tab_tetri))
	{
		TETRI(data->nb_tetri).letter = 64 + data->nb_tetri;
		return (1);
	}
	else
		return (0);
}

int		process_last_block(char (*buffer)[21], t_data *data)
{
	if ((*buffer)[19] == '\n')
	{
		return (process_block(buffer, data));
	}
	else
		return (0);
}

int		reader(char *file, t_data *data)
{
	int		fd;
	char	buffer[21];
	int		nb_read;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	while ((nb_read = read(fd, buffer, 21)) == 21)
		if (process_block(&buffer, data) == 0)
			return (0);
	if (nb_read == 20)
	{
		if (process_last_block(&buffer, data) == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}
