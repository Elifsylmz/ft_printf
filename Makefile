NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC = ft_printf.c ft_fc.c 
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re