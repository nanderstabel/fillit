/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <bwaarle@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 18:37:18 by bwaarle        #+#    #+#                */
/*   Updated: 2019/06/06 15:50:42 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int			ft_get_size(int n)
{
	int		size;

	size = 2;
	while (size * size < n * 4)
		size++;
	return (size);
}

char		**ft_make_square(int size)
{
	int		i;
	int		j;
	char	**square;

	i = 0;
	j = 0;
	square = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		j = 0;
		square[i] = (char *)malloc(sizeof(char) * size + 1);
		while (j < size)
		{
			square[i][j] = '.';
			j++;
		}
		square[i][j] = 0;
		i++;
	}
	square[i] = 0;
	return (square);
}

void		ft_print_square(char **square, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(square[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void		fillit(t_tetri *tetrimo, int n)
{
	int		size;
	char	**square;

	size = ft_get_size(n);
	square = ft_make_square(11);
	while (!place_tetri(tetrimo, n, size, square))
	{
		size++;
	}
	ft_print_square(square, size);
}
