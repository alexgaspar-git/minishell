SRCS		=	main.c \
				utils.c

SRCS		:= $(addprefix src/,$(SRCS))

OBJS		= ${SRCS:.c=.o}

NAME		= minishell

CC			= gcc

MAKE		= make

RM			= rm -rf

CFLAGS		= -Wall -Werror -Wextra -Iincludes

$(NAME):	$(OBJS)
			$(CC) ${CFLAGS} -o $(NAME) $(OBJS) -lreadline

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

noice:		all clean

.PHONY:		all clean fclean re noice