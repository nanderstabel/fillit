/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tetrimocheck.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <bwaarle@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:38:25 by bwaarle        #+#    #+#                */
/*   Updated: 2019/07/09 16:36:44 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>

static int	ft_charcheck(int i, int *piece, char *tetrimo)
{
	while (tetrimo[i] != '\0')
	{
		if (!(tetrimo[i] == '.' || tetrimo[i] == '#'))
			return (0);
		if (tetrimo[i] == '#')
			*piece = *piece + 1;
		i++;
	}
	return (1);
}

static int	ft_linecheck(char *tetrimo, int count)
{
	if (count < 4)
	{
		if (ft_strlen(tetrimo) != 4)
			return (0);
	}
	else if (count == 4)
	{
		if (ft_strlen(tetrimo) != 0)
			return (0);
	}
	return (1);
}

int			ft_tetrimocheck(char *tetrimo)
{
	static int	count = 0;
	static int	piece = 0;
	int			i;

	i = 0;
	if (ft_charcheck(i, &piece, tetrimo) == 0)
		return (0);
	if (ft_linecheck(tetrimo, count) == 0)
		return (0);
	count++;
	if (count == 5)
	{
		count = 0;
		if (piece != 4)
			i = -1;
		piece = 0;
	}
	if (piece > 4)
		i = -1;
	if (i == -1)
		return (0);
	if (tetrimo == NULL && count != 0)
		return (0);
	return (1);
}
