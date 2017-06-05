/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:10:01 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/30 12:51:28 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
	{
		write(2, "usage: ./fillit file_name\n", 26);
		return (1);
	}
	ccleaner_t_data(&data);
	if (reader(argv[1], &data) == 0)
	{
		write(1, "error\n", 6);
		return (1);
	}
	solve(&data);
	return (0);
}
