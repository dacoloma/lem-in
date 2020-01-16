# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 11:38:55 by dcoloma           #+#    #+#              #
#    Updated: 2019/10/30 13:37:43 by dcoloma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

HEADER = libft/includes

LIBFT = libft/libft.a

CC = gcc

CF = -Wall -Wextra -Werror -I $(HEADER)

SRC =	ft_init.c\
		ft_free.c

DIR_OBJ = obj_lem_in

OBJ = $(SRC:%.c=$(DIR_OBJ)/%.o)

.PHONY = all clean fclean re

all: $(LIBFT) $(DIR_OBJ) $(NAME) $(SRC) $(OBJ)

$(DIR_OBJ): 
	mkdir -p $(DIR_OBJ)

$(LIBFT) :
	make -C libft/

$(DIR_OBJ)/%.o: %.c
	$(CC) $(CF) -o $@ -c $< 

$(NAME) : $(LIBFT) $(OBJ) main.c
	$(CC) $(CF) -o $(NAME) main.c -g $(OBJ) -L libft/ -lft

clean:
	make clean -C libft/
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME) 
	make -C libft/ fclean

re: fclean all
