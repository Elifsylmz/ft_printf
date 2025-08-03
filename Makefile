NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = CC
RM = rm -rf
SRC = ft_printf.c ft_f.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re