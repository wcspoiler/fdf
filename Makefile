NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

SRCS = srcs/main.c \
		srcs/parser.c \
		srcs/drawing.c

OBJS = objs/main.o \
		srcs/parser.o \
		srcs/drawing.o

LIB = libft

MLX = minilibx_macos

all: $(NAME)

$(NAME):
	make -C $(LIB)
	make clean -C $(MLX)
	make -C $(MLX)
	$(CC) $(FLAGS) $(SRCS) -L. libft/libft.a -L. minilibx_macos/libmlx.a -framework OpenGL -framework Appkit -o fdf

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJS)
	make -C $(LIB) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB) clean

re: fclean all