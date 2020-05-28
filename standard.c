/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   standard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <bwaarle@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:56:29 by bwaarle        #+#    #+#                */
/*   Updated: 2019/06/06 16:21:08 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		ft_connections(char **tetri, int y, int x)
{
	int		connections;

	connections = 0;
	if (y > 0)
		if (tetri[y - 1][x] == '#')
			connections++;
	if (x > 0)
		if (tetri[y][x - 1] == '#')
			connections++;
	if (x < 3)
		if (tetri[y][x + 1] == '#')
			connections++;
	if (y < 3)
		if (tetri[y + 1][x] == '#')
			connections++;
	return (connections);
}

int		standard(char **tetri)
{
	int		x;
	int		y;
	int		connections;

	x = 0;
	y = 0;
	connections = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetri[y][x] == '#')
				connections += ft_connections(tetri, y, x);
			x++;
		}
		y++;
	}
	if (connections == 6 || connections == 8)
		return (1);
	return (0);
}
