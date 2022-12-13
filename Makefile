# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 18:17:13 by hualhash          #+#    #+#              #
#    Updated: 2022/12/13 21:18:13 by hualhash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_uputnbr.c ft_printhex_small.c ft_printhex_upper.c ft_pp.c \

OBJS = $(SRCS:c=o)

$(NAME): $(OBJS)
		@ar -rcs $(NAME) $(OBJS)

%.o : %.c
	${CC} ${CFLAGS} -c $^

all:	${NAME}

clean:
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)

re:		fclean all
