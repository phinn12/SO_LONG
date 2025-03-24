INCLUDES_MAC = -Imlx

NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g 


MLX_FLAGS_MAC = -Lmlx -lmlx -framework OpenGL -framework AppKit 

SRCS = control.c flood_fill.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c main.c exalidraw.c error.c ft_printf/ft_printf.c ft_printf/ft_printf_utils.c key.c

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -g $(INCLUDES_MAC) -c $< -o $@

$(NAME): $(OBJ)
	make -C mlx
	$(CC) $(OBJ) $(MLX_FLAGS_MAC) -o $(NAME) 

all: $(NAME)

fclean: clean
	rm -rf $(NAME)

clean:
	make clean -C mlx
	rm -rf ft_printf/*.o
	rm -rf *.o
	rm -rf get_next_line/*.o

re: fclean all

.PHONY: all clean fclean re