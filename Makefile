SRCS		=	main.c \
				utils.c \
				lst.c

SRCS		:= $(addprefix src/,$(SRCS))

OBJS		= ${SRCS:.c=.o}

NAME		= minishell

CC			= gcc

RM			= rm -rf

CFLAGS		= -Wall -Werror -Wextra -Iincludes

LIBFT		= ./libft/libft.a

$(NAME):	$(OBJS)
			@$(MAKE) -C ./libft
			$(CC) $(LIBFT) ${CFLAGS} -o $(NAME) $(OBJS) -lreadline

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

noice:		all clean

.PHONY:		all clean fclean re noice