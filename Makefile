SRC = get_next_line_utils.c \
		ft_atoi.c ft_split.c \
		get_next_line.c \
		bresenham_line.c \
		check_error.c \
		draw_map.c fdf.c \
		keyboard_actions.c \
		keyboard_actions_two.c \
		for_stack.c \
		fdf_setup.c \
		map.c \
		matrix.c \
		get_next_line_free.c \
		transformations.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC_FLAGS = -Wall -Wextra -Werror
CC = cc

MLX_FLAGS = -lmlx -lX11 -lXext -lz
MATH_FLAGS = -lm

NAME = fdf

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $(OBJ) $(MLX_FLAGS) $(MATH_FLAGS) -o $@

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
