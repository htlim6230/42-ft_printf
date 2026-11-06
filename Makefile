NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

SRCS = $(addsuffix .c, ft_printf, ft_putdec, ft_puthex, ft_putnbr, ft_point_hex)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c libftprint.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
