# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 18:47:04 by alel-you          #+#    #+#              #
#    Updated: 2024/12/07 19:07:10 by alel-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_printf.c ft_printf_utils.c ft_printf_Cutils.c

OBJCF = $(FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

NAME = libftprintf.a

all: $(NAME)

%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJCF)
	@ar rc $(NAME) $(OBJCF)

re: clean fclean all

clean:
	rm -rf $(OBJCF)

fclean: clean
	rm -rf $(NAME)
