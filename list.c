/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 15:51:04 by nstabel        #+#    #+#                */
/*   Updated: 2019/06/06 16:05:23 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

t_tetri		*newlist(int alph)
{
	t_tetri	*newlist;

	newlist = (t_tetri *)malloc(sizeof(t_tetri));
	if (newlist == NULL)
		return (NULL);
	newlist->coo = (int *)malloc(sizeof(int) * 8);
	if (newlist->coo == NULL)
		return (NULL);
	newlist->alph = 'A' + alph;
	newlist->next = NULL;
	return (newlist);
}

void		add_to_list(t_tetri **head, int alph)
{
	t_tetri	*add;

	add = newlist(alph);
	if (head != NULL && add != NULL)
		(*head)->next = add;
}

void		shift_coo(t_tetri *temp)
{
	int		i;
	int		minx;
	int		miny;

	i = 0;
	minx = 3;
	miny = 3;
	while (i < 8)
	{
		if (temp->coo[i] < miny)
			miny = temp->coo[i];
		i++;
		if (temp->coo[i] < minx)
			minx = temp->coo[i];
		i++;
	}
	i = 0;
	while (i < 8)
	{
		temp->coo[i] -= miny;
		temp->coo[i + 1] -= minx;
		i += 2;
	}
	reference(temp);
}

void		free_list(t_tetri *tetri_list)
{
	t_tetri *temp;

	while (tetri_list)
	{
		temp = tetri_list;
		free(temp->coo);
		free(temp);
		tetri_list = tetri_list->next;
	}
}

void		get_coo(t_tetri *temp, char **tetri)
{
	int		y;
	int		x;
	int		i;

	y = 0;
	x = 0;
	i = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetri[y][x] == '#')
			{
				temp->coo[i] = y;
				temp->coo[i + 1] = x;
				i += 2;
			}
			x++;
		}
		y++;
	}
}
