/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:58:42 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/30 12:51:44 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkernorme(char (*buffer)[21])
{
	int up;
	int nb_sharps;

	up = -1;
	nb_sharps = 0;
	while (++up < 20)
	{
		if (up == 4 || up == 9 || up == 14 || up == 19)
		{
			if ((*buffer)[up] != '\n')
				return (0);
		}
		else if ((*buffer)[up] != '.' && (*buffer)[up] != '#')
			return (0);
		if ((*buffer)[up] == '#')
			nb_sharps++;
	}
	if (nb_sharps != 4)
		return (0);
	return (1);
}
