NAME = lem-in

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

CPPFLAGS = -I libft/includes/ -I /usr/local/include/ -MMD

LDFLAGS = -L libft/ -lft  -L /usr/local/include/

INC = libft/includes

LIBFT = libft/libft.a

HEADER_PATH = includes

HEADER = includes/lem_in.h

SDLINCL = -I $(HOME)/.brew/Cellar/sdl2/2.0.10/include/SDL2

SDLFLAGS =  $(SDLINCL) -L $(HOME)/.brew/Cellar/sdl2/2.0.10/lib -lSDL2

vpath %c src

#SRC_PATH = src

SRC =	add_edge.c\
		bfs.c\
		create_graph.c\
		create_room.c\
		create_queue.c\
		main.c

OBJ_PATH = obj_lem_in

OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)

.PHONY = all clean fclean re FORCE

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(LIBFT) : FORCE
	$(MAKE) -C libft/

FORCE:

$(OBJ_PATH)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< -I $(HEADER_PATH) $(SDLINCL) -I $(INC)

$(NAME) : $(LIBFT) $(OBJ) $(HEADER) $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SDLFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft -I $(HEADER_PATH) -I $(INC)

clean:
	$(MAKE) clean -C libft/
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean all

-include $(OBJ:.o=.d)
