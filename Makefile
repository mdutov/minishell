NAME = minishell

MAKE = make -C

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm

SRCS := $(wildcard ./src_t/*.c) $(wildcard ./src_m/*.c) $(wildcard ./libft/*.c) \
		$(wildcard ./utils/*.c)  $(wildcard ./src_t/dollar/*.c) $(wildcard ./src_m/chernov/parser_pipe.c) \
		$(wildcard ./src_m/chernov/parser_commline.c) $(wildcard ./src_t/find_bin/*.c) \
		$(wildcard ./src_m/chernov/ourpipe.c) $(wildcard ./src_m/chernov/doublebackreddir.c) \
		$(wildcard ./src_m/chernov/ourpipe_utils.c) $(wildcard ./src_m/chernov/parser_commline_utils_1.c) \
		$(wildcard ./src_m/chernov/parser_commline_utils_2.c) main.c

OBJ = ${SRCS:.c=.o}

HEADERS = ./types.h ./src_t/headers_t.h ./src_m/headers_m.h ./libft/libft.h

LIBFTDIR = ./libft

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME} ${HEADERS}

${NAME}: ${OBJ}
	${MAKE} ${LIBFTDIR}
	${CC} ${OBJ} ${LIBFTDIR}/libft.a -o ${NAME} -lreadline -L/Users/${USER}/.brew/Cellar/readline/8.1/lib/ -I/Users/${USER}/.brew/Cellar/readline/8.1/include -LLibft/ -L.

${HEADERS}: 
	${CC} ${CFLAGS} -c $< -o $@
clean:
	${MAKE} ${LIBFTDIR} clean
	${RM} -f ${OBJ}

fclean: clean
	${MAKE} ${LIBFTDIR} fclean
	${RM} -f ${NAME}

re: fclean all

bonus: ${NAME}

.PHONY: all clean fclean re bonus
