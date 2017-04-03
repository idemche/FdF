# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/31 04:02:58 by idemchen          #+#    #+#              #
#    Updated: 2017/03/31 07:07:25 by idemchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Werror -Wextra -O3
MLX_FLAGS = -lmlx -framework OpenGl -framework AppKit
SRC = fdf_main.c ft_libft_functions.c ft_libft_functions_suite.c \
	ft_read_from_file.c ft_representation.c ft_keys.c
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)
$(NAME): $(OBJ)
	make -C libft/
	clang $(FLAGS) $(MLX_FLAGS) -o $(NAME) $(SRC) libft/libft.a
	rm -r $(OBJ)

%.o: %.c
	clang -I ./libft/ -c $(FLAGS) -o $@ $<

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(OBJ) $(NAME)

re: fclean all
