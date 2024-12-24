SRC = main.c init.c render.c hook.c  gnl/get_next_line_utils.c gnl/get_next_line.c rays.c
#BONUS = 
CC = cc
CFLAGS = -g -v -fsanitize=address,undefined
OBJ = ${SRC:.c=.o}
#BONOBJ = ${BONUS:.c=.o}
LIBFTA = Libft/libft.a
MLXLIB = mlx_linux/libmlx.a
NAME = cub3D



all: $(NAME)

$(NAME): $(OBJ)
	make all -C Libft
	make all -C minilibx
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTA) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

#%.o: %.c
#	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
#$(NAME): $(OBJ)
#	$(CC) $(CFLAGS) $(OBJ) $(LIBFTA) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

#bonus: $(BONOBJ)
#	make all -C libft
#	make all -C minilibx
#	$(CC) $(CFLAGS) $(BONOBJ) $(LIBFTA) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(BNAME)

clean:
	make clean -C Libft
	make clean -C minilibx
	rm -f $(OBJ)

fclean: clean
	make fclean -C Libft
	rm -f $(NAME)

re: fclean all

