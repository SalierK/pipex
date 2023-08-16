NAME	= pipex
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

SRCS = 	pipex.c			\
		pipex_utils1.c	\
		pipex_utils2.c	\
		pipex_utils3.c	\
		pipex_utils4.c	\
		pipex_utils5.c	

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re norm