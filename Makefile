NAME = cub3d
FLAGS = -Werror -Wextra -Wall -g
LIBFT = -Llibft -lft
MINILIBX = -Lminilibx-linux -lmlx
SRC=src/*.c

$(NAME): $(SRC)
	@echo "Compiling $@"
	make -C libft/
	make -C minilibx-linux/
	cc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT) $(MINILIBX) $(X11LIB)

all: $(NAME)

clean:
	make -C libft/ fclean
	make -C minilibx-linux/ clean

fclean: clean
	@echo "Cleaning $(NAME)"
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re