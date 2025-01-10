SRC = main.c parsing/assign_map.c parsing/assign_struct.c parsing/error.c parsing/init.c\
	parsing/map_entries.c parsing/map_parsing.c parsing/set_map.c parsing/freeing_funcs.c\
	gnl/get_next_line_utils.c gnl/get_next_line.c parsing/colors_validation.c \
	parsing/textures_parsing.c\
	execution/hook.c execution/init_mlx.c execution/raycast.c execution/render.c\
	execution/utils.c execution/intersect.c execution/movements.c
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
OBJ = ${SRC:.c=.o}
LIBFTA = Libft/libft.a
MLXLIB = minilibx/libmlx.a
NAME = cub3D


all: $(NAME)

$(NAME): $(OBJ)
	make all -C Libft
	make all -C minilibx
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTA) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT):
	make -C Libft

clean:
	make clean -C Libft
	make clean -C minilibx
	rm -f $(OBJ)

fclean: clean
	make fclean -C Libft
	make clean -C minilibx
	rm -f $(NAME)

re: fclean all

