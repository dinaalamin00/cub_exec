SRC = main.c
#BONUS = 
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = ${SRC:.c=.o}
#BONOBJ = ${BONUS:.c=.o}
#LIBFTA = Libft/libft.a
MLXLIB = minilibx/libmlx.a
NAME = cub3D



all: $(NAME)

$(NAME): $(OBJ)
#	make all -C libft
	make all -C minilibx
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTA) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
#bonus: $(BONOBJ)
#	make all -C libft
#	make all -C minilibx
#	$(CC) $(CFLAGS) $(BONOBJ) $(LIBFTA) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(BNAME)

clean:
#	make clean -C libft
	make clean -C minilibx
	rm -f $(OBJ)

fclean: clean
#	make fclean -C libft
	rm -f $(NAME)

re: fclean all

