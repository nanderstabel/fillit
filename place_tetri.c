/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_tetri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <bwaarle@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 15:42:50 by bwaarle        #+#    #+#                */
/*   Updated: 2019/06/06 15:52:04 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	del_sign(t_tetri *tetrimo, char **square, int x, int y)
{
	square[tetrimo->coo[0] + y][tetrimo->coo[1] + x] = '.';
	square[tetrimo->coo[2] + y][tetrimo->coo[3] + x] = '.';
	square[tetrimo->coo[4] + y][tetrimo->coo[5] + x] = '.';
	square[tetrimo->coo[6] + y][tetrimo->coo[7] + x] = '.';
}

void	place_sign(t_tetri *tetrimo, char **square, int x, int y)
{
	square[tetrimo->coo[0] + y][tetrimo->coo[1] + x] = tetrimo->alph;
	square[tetrimo->coo[2] + y][tetrimo->coo[3] + x] = tetrimo->alph;
	square[tetrimo->coo[4] + y][tetrimo->coo[5] + x] = tetrimo->alph;
	square[tetrimo->coo[6] + y][tetrimo->coo[7] + x] = tetrimo->alph;
}

int		conditions(t_tetri *tetrimo, char **square, int x, int y)
{
	if (square[tetrimo->coo[0] + y][tetrimo->coo[1] + x] != '.')
		return (0);
	if (square[tetrimo->coo[2] + y][tetrimo->coo[3] + x] != '.')
		return (0);
	if (square[tetrimo->coo[4] + y][tetrimo->coo[5] + x] != '.')
		return (0);
	if (square[tetrimo->coo[6] + y][tetrimo->coo[7] + x] != '.')
		return (0);
	return (1);
}

int		place_tetri(t_tetri *tetrimo, int n, int size, char **square)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	if (tetrimo == NULL)
		return (1);
	while (y < size - tetrimo->down)
	{
		x = 0;
		while (x + tetrimo->left < size - tetrimo->right)
		{
			if (conditions(tetrimo, square, x, y))
			{
				place_sign(tetrimo, square, x, y);
				if (place_tetri(tetrimo->next, n, size, square))
					return (1);
				del_sign(tetrimo, square, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
