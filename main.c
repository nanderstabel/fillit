/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <bwaarle@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 17:10:14 by bwaarle        #+#    #+#                */
/*   Updated: 2019/06/17 14:04:13 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void		solve(char ***tetri, int n)
{
	t_tetri	*tetri_list;
	t_tetri *temp;
	int		i;

	i = 1;
	tetri_list = newlist(0);
	temp = tetri_list;
	while (i < n)
	{
		add_to_list(&temp, i);
		temp = temp->next;
		i++;
	}
	temp = tetri_list;
	while (temp)
	{
		get_coo(temp, *tetri);
		shift_coo(temp);
		tetri++;
		temp = temp->next;
	}
	fillit(tetri_list, n);
	free_list(tetri_list);
}

/*
** in[0] == tetrimo pieces
** in[1] == index
*/

int			error(int *in, char ***tetri)
{
	if (standard(tetri[in[1]]) == 0)
		ft_putstr("error\n");
	if (standard(tetri[in[1]]) == 0)
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	char	***tetri;
	char	*tetrimo[130];
	int		in[2];

	if (argc != 2)
		ft_putstr("usage: ./fillit source_file\n");
	else
	{
		in[0] = ft_readtetrimo(argv[1], tetrimo) / 5;
		if (in[0] == 0)
			ft_putstr("error\n");
		else
		{
			tetri = get_input(tetrimo, in[0]);
			in[1] = 0;
			while (in[1] < in[0])
			{
				if (error(in, tetri) == 0)
					return (0);
				in[1]++;
			}
			solve(tetri, in[0]);
		}
	}
	return (0);
}
