NAME = cub3d

SRC = 	src/func_free.c src/get_next_line_mod.c\
		src/init_info.c src/main.c src/parsing.c src/rays.c\
		src/t_add_textures.c src/t_part_word.c src/utilus.c\
		src/key.c src/action.c

HEADER = include/cubd.h

LIBFT = libft/libft.a

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIBFT) 
			@${MAKE} -C libft
			$(CC) $(FLAGS) $(MLX_FLAGS) $^ -o $@

%.o		:	%.c $(HEADER) Makefile
			$(CC) $(FLAGS) -c $< -o $@ 

$(LIBFT) :  libft/libft.h libft/*.c libft/Makefile

clean	:	
			rm -rf $(OBJS)
			@${MAKE} -C libft clean

fclean	:	clean
			rm -rf $(NAME)
			@${MAKE} -C libft fclean

re		:	fclean all

.PHONY	:	all clean fclean re

