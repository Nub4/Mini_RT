NAME = libftminirt.a

SRCS2 = blocks_a.c \
	blocks_c.c \
	blocks_cy.c \
	blocks_cy_2.c \
	blocks_l.c \
	blocks_pl.c \
	blocks_sp.c \
	blocks_sq.c \
	blocks_tr.c \
	bmp.c \
	building_image.c \
	closest_intersect.c \
	color.c \
	cylinder.c \
	cylinder_2.c \
	cylinder_3.c \
	error.c \
	find_obj_n_c.c \
	get_next_line.c \
	get_next_line_utils.c \
	hooks.c \
	hooks_2.c \
	identifier.c \
	intersect.c \
	magic.c \
	magic_2.c \
	main.c \
	parcing.c \
	parcing_2.c \
	plane.c \
	square.c \
	triangle.c \
	utils.c \
	utils_2.c \
	values.c \
	vector_equations.c \
	vector_equations_2.c \
	hooks_3.c \
	hooks_4.c \
	hooks_5.c

OBJECTS2 = ${SRCS2:.c=.o}

HEADERS_FOLDER = includes

CC = gcc

RM = rm -f

CFLAGS = -g -O2 -DDONT_USE_VOL -Wall -Wextra -Werror -I ./minilibx_opengl_20191021

all: ${NAME}

${NAME}: ${OBJECTS2}

	ar rc ${NAME} ${OBJECTS2}
	gcc -g -O2 -DDONT_USE_VOL ${NAME} -L ./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -o miniRT

clean:

	${RM} ${OBJECTS2} ${OBJECTS}

fclean: clean

	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
