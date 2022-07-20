# -------------------------------------VARS--------------------------------------

NAME	= push_swap

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
			small_sort.c \
			medium_sort.c \
			midpoint1a.c \
			midpoint1b.c \
			midpoint1_utils.c \
			midpoint2.c \
			midpoint3.c \
			midpoint_last1.c \
			midpoint_last2.c \
			big_sort.c \
			main.c \

OBJS	= ${SRCS:.c=.o}

# ------------------------------------RULES--------------------------------------

.c.o:
			${CC} ${CFLAGS} -c -I./includes $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

bonus:		
			@make -C ./checker_b
			@cp ./checker_b/checker .

clean:
			${RM} ${OBJS}
			@make clean -C ./checker_b

fclean:		clean
			${RM} ${NAME}

re:			fclean all

# -----------------------------------PHONY---------------------------------------

.PHONY:		all clean fclean re checker_b