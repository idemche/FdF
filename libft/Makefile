# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 14:10:16 by idemchen          #+#    #+#              #
#    Updated: 2017/02/17 22:41:40 by idemchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC		=	clang
FLAGS	=	-Wall -Wextra -Werror
LIBHEAD	=	includes/
##############################################################
#	LIBFT
##############################################################
LIBFT	=	ft_to/ft_atoi.c ft_lst/ft_lstadd.c ft_mem/ft_memchr.c \
		  	ft_print/ft_putchar_fd.c ft_str/ft_strchr.c ft_str/ft_striteri.c \
		  	ft_str/ft_strncpy.c ft_str/ft_strtrim.c ft_mem/ft_bzero.c \
		  	ft_lst/ft_lstdel.c ft_mem/ft_memcmp.c ft_print/ft_putendl.c \
		  	ft_str/ft_strclr.c ft_str/ft_strjoin.c ft_str/ft_strnequ.c \
		  	ft_to/ft_tolower.c ft_is/ft_isalnum.c ft_lst/ft_lstdelone.c \
		  	ft_mem/ft_memcpy.c ft_print/ft_putendl_fd.c \
		  	ft_str/ft_strcmp.c ft_str/ft_strlcat.c ft_str/ft_strnew.c \
		  	ft_to/ft_toupper.c ft_is/ft_isalpha.c ft_lst/ft_lstiter.c \
		  	ft_mem/ft_memdel.c ft_print/ft_putnbr.c ft_str/ft_strcpy.c \
		  	ft_str/ft_strlen.c ft_str/ft_strnstr.c ft_is/ft_isascii.c \
		  	ft_lst/ft_lstmap.c ft_print/ft_putnbr_fd.c ft_str/ft_strdel.c \
		  	ft_str/ft_strmap.c ft_str/ft_strrchr.c ft_is/ft_isdigit.c \
		  	ft_lst/ft_lstnew.c ft_mem/ft_memmove.c ft_print/ft_putstr.c \
		  	ft_str/ft_strdup.c ft_str/ft_strmapi.c ft_str/ft_strsplit.c \
		  	ft_is/ft_isprint.c ft_mem/ft_memalloc.c ft_mem/ft_memset.c \
		  	ft_print/ft_putstr_fd.c ft_str/ft_strequ.c ft_str/ft_strncat.c \
		  	ft_str/ft_strstr.c ft_to/ft_itoa.c ft_mem/ft_memccpy.c \
		  	ft_print/ft_putchar.c ft_str/ft_strcat.c ft_str/ft_striter.c \
		  	ft_str/ft_strncmp.c ft_str/ft_strsub.c
#############################################################
#	GET_NEXT_LINE
#############################################################
GNL		=	get_next_line/get_next_line.c

GNLHEAD =	get_next_line/

#############################################################
#	FT_PRINTF
#############################################################
FT_PRINTF =	ft_printf/pf_ft_buffer.c\
			ft_printf/pf_ft_checker.c\
			ft_printf/pf_ft_flag_imbed.c\
			ft_printf/pf_ft_handle_c.c\
			ft_printf/pf_ft_handle_d.c\
			ft_printf/pf_ft_handle_s.c\
			ft_printf/pf_ft_handle_u_n_o.c\
			ft_printf/pf_ft_handle_wchar_u_n_o.c\
			ft_printf/pf_ft_handle_x.c\
			ft_printf/pf_ft_print_char.c\
			ft_printf/pf_ft_print_numbers.c\
			ft_printf/pf_ft_printf.c\
			ft_printf/pf_ft_structure_fill.c\
			ft_printf/pf_ft_undefined_p.c\
			ft_printf/pf_ft_universal_handler.c\
			ft_printf/pf_ft_utilities.c\
			ft_printf/pf_ft_wchar_to_char.c\
			ft_printf/pf_ft_libft_functions.c\
			ft_printf/pf_ft_libft_functions_aftersuite.c\
			ft_printf/pf_ft_libft_functions_suite.c

PRINTF_HD = ft_printf/
#############################################################
#	RULES
#############################################################
SOURCES = $(LIBFT) $(GNL) $(FT_PRINTF)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
JUNK	= $(wildcard .DS_Store */.DS_Store */*/.DS_Store *.gch \
		  get_next_line/*.gch)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "|    o  __  ___ "
	@echo "|    |  |_   |  "
	@echo "|    |  |    |  "
	@echo "---- -  -    -   "
	@echo "\033[1;34mlibft.a\t\033[1;33mPack\t\033[0;32m[Complete]\033[0m"

%.o: %.c
	$(CC) -I $(LIBHEAD) -I $(GNLHEAD) -I $(PRINTF_HD) -c $(FLAGS) -o $@ $<

clean:
	@rm -rf $(OBJECTS)
	@echo "\033[1;34mlibft\t\033[1;33mCleanse\t\033[0;32m[Done]\033[0m"

fclean: clean
	@rm -rf $(OBJECTS) $(NAME)
	@echo "\033[1;34mlibft\t\033[1;33mCleanse\t\033[0;32m[Done]\033[0m"

re: fclean all

norme:
	@norminette $(SOURCES) $(LIB_FT) $(pf_ft_PRINTF)
	@echo "\033[1;34mlibft\t\033[1;33mNorme\t\033[0;32m[Completed]\033[0m"
