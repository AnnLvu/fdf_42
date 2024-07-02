SRC = get_next_line_utils.c \
		ft_atoi.c ft_split.c \
		get_next_line.c \
		bresenham_line.c \
		check_error.c \
		draw_map.c fdf.c \
		for_close.c \
		for_stack.c \
		help_for_main.c \
		map.c \
		matrix.c \
		read_map.c \
		transformations.c

OBJ = $(SRC:.c=.o)

CC_FLAGS = -Wall -Wextra -Werror
CC = cc

MLX_FLAGS = -lmlx -lX11 -lXext -lz
MATH_FLAGS = -lm

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $(OBJ) $(MATH_FLAGS) $(MLX_FLAGS) -o $@

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
