# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/16 03:45:49 by vnekhay           #+#    #+#              #
#    Updated: 2018/04/22 03:44:50 by vnekhay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_printf.c \
        ft_isdigit.c \
        ft_memset.c \
        ft_strchr.c \
        ft_strlen.c \
        manage_number.c \
        manage_int.c \
        manage_str.c \
        manage_char.c \
        manage_type.c \
        adding_width.c \
        throw_in_buf.c \
        hunting_for_qualifiers.c \
        manage_ouxp_types.c \
        default_params.c


OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

%.o:%.c
	gcc -Wall -Wextra -Werror -o $@ -c $< -I libft

clean:
	rm -f $(OBJECT)
	find . -name ".*.sw[pon]" -exec rm -f {} +

fclean: clean
	rm -f $(NAME)

re: fclean all
