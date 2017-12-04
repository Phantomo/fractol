NAME = fractol

FLAGS = -Wall -Wextra -Werror -O2 -lmlx -framework OpenGL -framework AppKit 

HEAD = -I includes/fractol.h

SRC = resources/fractol.c resources/func.c resources/fractal_type.c\
		resources/line.c resources/redraw.c resources/build.c resources/valid.c

SRCO = $(SRC:%.c=%.o)

all: $(NAME)


$(NAME): $(SRCO)
	@ gcc -o $(NAME) $(SRCO) $(FLAGS) $(HEAD)

%.o: %.c
	@ gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	@ rm -f $(SRCO)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all