# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jslave <jslave@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 21:32:49 by jslave            #+#    #+#              #
#    Updated: 2019/11/19 17:38:22 by jslave           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

LIBFT = libft

LIBFT_INCLUDES = libft/includes

INCLUDES = inc/

FLAGS =  -Wall -Wextra -Werror

SRC = src/ft_printf.c src/utils.c src/check_chars.c src/check_width.c src/check_ints.c src/ft_itoa_new.c

OUT = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OUT)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OUT)
	ranlib $(NAME)
%.o: %.c
	gcc $(FLAGS) -I $(LIBFT_INCLUDES) -I $(INCLUDES) -o $@ -c $<

clean:
	/bin/rm -f $(OUT)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

test: libftprintf.a main_test.c
	gcc libftprintf.a main_test.c
