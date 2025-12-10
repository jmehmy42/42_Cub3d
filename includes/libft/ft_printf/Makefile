# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 18:08:30 by marvin            #+#    #+#              #
#    Updated: 2025/03/12 14:08:43 by jmehmy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC_FILES =	ft_printf.c ft_pointer.c ft_print_string.c ft_print_char.c \
				ft_unsigned.c ft_putnbr.c ft_hexadacimal.c ft_hex_conversion.c \
		
OBJS = $(SRC_FILES:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all fclean clean re