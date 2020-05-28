# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bwaarle <bwaarle@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/07 17:16:54 by bwaarle        #+#    #+#                 #
#    Updated: 2019/06/06 16:14:32 by bwaarle       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ft_readtetrimo.c ft_tetrimocheck.c get_input.c get_next_line.c main.c \
standard.c map.c place_tetri.c list.c reference.c

HEADER = fillit.h

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/

all: $(NAME)

$(NAME):
	make re -C $(LIBFT)
	gcc -o $(NAME) $(FLAGS) $(SRCS) -I$(LIBFT) $(LIBFT)libft.a

clean:
	/bin/rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all