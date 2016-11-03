NAME = fdf

SRC = main.c keyhooks.c read_map.c draw_object.c includes/libft.a

CFLAGS = -Wall -Werror -Wextra

MACFLAGS = -lmlx -framework OpenGL -framework Appkit

LINUXFLAGS = -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	make -C includes/
	gcc $(CFLAGS) -o $(NAME) $(SRC) $(MACFLAGS)

clean:
	make -C includes/ clean

fclean:
	make -C includes/ fclean
	rm -rf fdf

re:	fclean all
