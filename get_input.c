/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <bwaarle@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 14:18:57 by bwaarle        #+#    #+#                */
/*   Updated: 2019/06/06 15:46:49 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char	***get_input(char **tetrimo, int n)
{
	int		i;
	int		sq;
	int		alph;
	char	***tetri;

	i = 0;
	alph = 0;
	tetri = (char ***)malloc(sizeof(char **) * n + 1);
	while (alph < n)
	{
		sq = 0;
		tetri[alph] = (char **)malloc(sizeof(char *) * 4);
		while (sq < 4)
		{
			tetri[alph][sq] = ft_strdup(tetrimo[i]);
			sq++;
			i++;
		}
		i++;
		alph++;
	}
	return (tetri);
}
