# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 02:39:52 by alel-you          #+#    #+#              #
#    Updated: 2024/11/14 02:52:11 by alel-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_printf.c ft_putchar_fd.c ft_putnb.c \

OBJF = $(FILES:.c=.o)

CC = cc 

FLAGS = -Wall -Wextra -Werror

NAME = lib.a

all: $(NAME)

%.o:%.c lib.h
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME):$(OBJF)
	ar rc $(NAME) $(OBJF)

clean:
	@rm -rf $(OBJF)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean 