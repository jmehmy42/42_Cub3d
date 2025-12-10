# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 20:46:13 by jmehmy            #+#    #+#              #
#    Updated: 2025/03/19 12:32:52 by jmehmy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC_FILES       = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
              ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
              ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
              ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
              ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
              ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
              ft_substr.c ft_tolower.c ft_toupper.c ft_strlcpy.c free_string.c \
              get_next_line.c get_next_line_utils.c get_next_line_bonus.c get_next_line_utils_bonus.c ft_splits.c \

PRINTF          = ft_printf.c ft_pointer.c ft_print_string.c ft_print_char.c \
		ft_unsigned.c ft_putnbr.c ft_hexadacimal.c ft_hex_conversion.c

BONUS_FILES     = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
              ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
              ft_lstmap.c


BONUS_OBJS = $(BONUS_FILES:.c=.o)
OBJS = $(SRC_FILES:.c=.o)
PRINTF_OBJ = $(addprefix ./ft_printf/, $(PRINTF:.c=.o))

all: $(NAME) 

$(NAME): $(OBJS) $(PRINTF_OBJ)
	@ar rcs $(NAME) $(OBJS) $(PRINTF_OBJ)

bonus: $(BONUS_OBJS) $(NAME)
	@ar rcs $(NAME) $(BONUS_OBJS)
	
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(PRINTF_OBJ): %.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	
clean:
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	@rm -f $(PRINTF_OBJ)
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all fclean clean re
