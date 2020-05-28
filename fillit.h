/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <bwaarle@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 17:18:16 by bwaarle        #+#    #+#                */
/*   Updated: 2019/06/17 14:16:56 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 8

typedef struct			s_tetri
{
	char				alph;
	int					left;
	int					right;
	int					down;
	int					*coo;
	struct s_tetri		*next;
}						t_tetri;

int						get_next_line(const int fd, char **line);
int						ft_tetrimocheck(char *tetrimo);
int						ft_readtetrimo(char *argv, char **tetrimo);
int						standard(char **tetri);
char					***get_input(char **tetrimo, int n);
void					fillit(t_tetri	*tetrimo, int n);
void					reference(t_tetri *temp);
void					get_coo(t_tetri *temp, char **tetri);
void					free_list(t_tetri *tetri_list);
void					shift_coo(t_tetri *temp);
void					add_to_list(t_tetri **head, int alph);
t_tetri					*newlist(int alph);
int						place_tetri(t_tetri *tetrimo, int n, int size, \
char **square);

#endif
