NAME		= cub3d
SRCS_DIR	= src/
OBJS_DIR	= obj/
INCS_DIR	= include
SRCS_F		= main.c init_info.c parsing.c utilus.c get_next_line_mod.c part_word.c add_textures.c func_free.c 

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_F))
OBJS_F		= $(patsubst %.c, %.o, $(SRCS_F))
DEPS_F		= $(patsubst %.c, %.d, $(SRCS_F))
OBJS		= $(addprefix $(OBJS_DIR), $(OBJS_F))
DEPS		= $(addprefix $(OBJS_DIR), $(DEPS_F))

CC			= cc
# CFLAGS		= 
CFLAGS		= -g -fsanitize=address
# CFLAGS		= -g -fsanitize=address
#CFLAGS		= -Wall -Wextra -Werror -MMD
LFLAGS		= -Llibft -lft
LIB			= libft.a
LIB_DIR		= libft/

all: $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
		@$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@
#.c.o:
#			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(OBJS_DIR) :
		mkdir -p $@

$(NAME):  $(OBJS_DIR) $(OBJS) $(LIB_DIR)$(LIB)
		@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME) -Lmlx -lmlx  -framework OPENGL -framework Appkit -lm $


$(LIB_DIR)$(LIB) : ;
		make -C $(LIB_DIR)

clean :
	rm -rf $(OBJS_DIR)
	make clean -C $(LIB_DIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all

.PHONY:
		all clean fclean re bonus

-include $(DEPS) $(DEPS_B)

