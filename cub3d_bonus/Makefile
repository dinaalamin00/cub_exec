SRC = main.c parsing_bonus/assign_map_bonus.c parsing_bonus/assign_struct_bonus.c\
	parsing_bonus/colors_validation_bonus.c parsing_bonus/error_bonus.c\
	parsing_bonus/freeing_funcs_bonus.c parsing_bonus/init_bonus.c\
	parsing_bonus/map_entries_bonus.c parsing_bonus/map_parsing_bonus.c\
	parsing_bonus/set_map_bonus.c parsing_bonus/textures_parsing_bonus.c\
	gnl/get_next_line_utils.c gnl/get_next_line.c\
	execution_bonus/hook_bonus.c execution_bonus/init_mlx_bonus.c\
	execution_bonus/intersect_bonus.c execution_bonus/movements_bonus.c\
	execution_bonus/raycast_bonus.c execution_bonus/render_bonus.c\
	execution_bonus/utils_bonus.c execution_bonus/mini_map_bonus.c
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
OBJ = ${SRC:.c=.o}
LIBFTA = Libft/libft.a
MLXLIB = minilibx/libmlx.a
NAME = cub3D_bonus


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

