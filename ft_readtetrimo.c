/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_readtetrimo.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <bwaarle@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 17:43:31 by bwaarle        #+#    #+#                */
/*   Updated: 2019/07/09 16:51:27 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>

int		ft_readtetrimo(char *argv, char **tetrimo)
{
	int fd;
	int	n;
	int alph;

	n = 1;
	alph = 0;
	fd = open(argv, O_RDONLY);
	while (n == 1 && alph < 131)
	{
		n = get_next_line(fd, &tetrimo[alph]);
		if (n == 1)
			if (ft_tetrimocheck(tetrimo[alph]) == 0)
				n = -1;
		alph++;
	}
	if (alph > 130)
		n = -1;
	close(fd);
	if (n == -1)
		return (0);
	if (alph % 5 != 0)
		return (0);
	return (alph);
}
