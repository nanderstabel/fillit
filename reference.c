/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reference.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 15:56:08 by nstabel        #+#    #+#                */
/*   Updated: 2019/06/06 15:56:38 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static int	ft_smallest(int a, int b, int c)
{
	if (a <= b)
	{
		if (a <= c)
			return (a);
		return (c);
	}
	if (b <= c)
		return (b);
	return (c);
}

static int	ft_biggest(int a, int b, int c)
{
	if (a >= b)
	{
		if (a >= c)
			return (a);
		return (c);
	}
	if (b >= c)
		return (b);
	return (c);
}

void		reference(t_tetri *temp)
{
	int		ref;

	ref = ft_smallest(temp->coo[3], temp->coo[5], temp->coo[7]);
	temp->left = (temp->coo[1] > ref) ? temp->coo[1] - ref : 0;
	ref = ft_biggest(temp->coo[3], temp->coo[5], temp->coo[7]);
	temp->right = (temp->coo[1] < ref) ? ref - temp->coo[1] : 0;
	temp->down = ft_biggest(temp->coo[2], temp->coo[4], temp->coo[6]);
}
