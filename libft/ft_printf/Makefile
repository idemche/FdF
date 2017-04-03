# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/09 15:51:41 by idemchen          #+#    #+#              #
#    Updated: 2017/02/17 21:52:26 by idemchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

NAME = libftprintf.a

CC		=	clang
FLAGS	=	-Wall -Wextra -Werror

pf_ft_PRINTF =	pf_ft_buffer.c\
			pf_ft_checker.c\
			pf_ft_flag_imbed.c\
			pf_ft_handle_c.c\
			pf_ft_handle_d.c\
			pf_ft_handle_s.c\
			pf_ft_handle_u_n_o.c\
			pf_ft_handle_wchar_u_n_o.c\
			pf_ft_handle_x.c\
			pf_ft_print_char.c\
			pf_ft_print_numbers.c\
			pf_ft_printf.c\
			pf_ft_structure_fill.c\
			pf_ft_undefined_p.c\
			pf_ft_universal_handler.c\
			pf_ft_utilities.c\
			pf_ft_wchar_to_char.c

LIB_FT = 	pf_ft_libft_functions.c\
			pf_ft_libft_functions_aftersuite.c\
			pf_ft_libft_functions_suite.c

SOURCES = $(pf_ft_PRINTF) $(LIB_FT)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
JUNK	= $(wildcard .DS_Store */.DS_Store */*/.DS_Store *.gch \
		  get_next_line/*.gch)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "__  ___      __  __  _ _  _ ___ __ "
	@echo "|_   |       |_) |_) | |\ |  |  |_ "
	@echo "|    |       |   | \ | | \|  |  |  "
	@echo "-    -  ---- -   - - - -  -  -  -  "
	@echo "\033[1;34mlibftprintf.a\t\033[1;33mPack\t\033[0;32m[Complete]\033[0m"

%.o: %.c
	$(CC) -c $(FLAGS) -o $@ $<

clean:
	@rm -rf $(OBJECTS)
	@echo "\033[1;34mlibftprintf\t\033[1;33mCleanse\t\033[0;32m[Done]\033[0m"

fclean: clean
	@rm -rf $(OBJECTS) $(NAME)
	@echo "\033[1;34mlibftprintf\t\033[1;33mCleanse\t\033[0;32m[Done]\033[0m"

re: fclean all

norme:
	@norminette $(SOURCES) $(LIB_FT) $(pf_ft_PRINTF)
	@echo "\033[1;34mlibftprintf\t\033[1;33mNorme\t\033[0;32m[Completed]\033[0m"
