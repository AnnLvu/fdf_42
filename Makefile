SRC = get_next_line_utils.c ft_atoi.c ft_split.c get_next_line.c
OBJ = $(SRC:.c=.o)


CC_FLAGS = -Wall -Wextra -Werror
CC = cc

MLX_FLAGS = -lmlx -lmlx -lX11 -lXext -lz
MATH_FLAGS = -lm

NAME = fdf
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
