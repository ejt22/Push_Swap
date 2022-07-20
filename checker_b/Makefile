# -------------------------------------VARS--------------------------------------

NAME	= checker

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

# ---------------------------------SOURCE FILES----------------------------------

SRCS	= ft_split.c \
			ft_atoi.c \
			parsing.c \
			sort_tab.c \
			init_list.c \
			l_list_utils.c \
			smove.c \
			rmove.c \
			rrmove.c \
			pmove_a.c \
			pmove_b.c \
			get_next_line.c \
			get_next_line_utils.c \
			checker.c \
			main.c \

OBJS	= ${SRCS:.c=.o}

# ------------------------------------RULES--------------------------------------

.c.o:
			${CC} ${CFLAGS} -c -I./includes $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

# -----------------------------------PHONY---------------------------------------

.PHONY:		all clean fclean re