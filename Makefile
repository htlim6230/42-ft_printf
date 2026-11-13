# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/11 17:24:45 by hui-tinl          #+#    #+#              #
#    Updated: 2026/11/13 18:18:48 by hui-tinl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

SRCS = $(addsuffix .c, ft_point_hex ft_printf ft_putchar ft_puthex ft_putnbr \
			ft_putstr ft_putunsigned)
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
