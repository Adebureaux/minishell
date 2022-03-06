# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravily <mravily@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/16 02:00:35 by mravily           #+#    #+#              #
#    Updated: 2022/03/06 02:09:14 by mravily          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		libft.a

##
##		RESSOURCES
##

##List every folder where he will find header
INC_DIR = 	$(shell find includes -type d)

##List every folder where he will find source file
SRC_DIR = 	$(shell find srcs -type d)

##Folder where he will store the .o
OBJ_DIR	=	obj

##Add to the vpath the folder find in SRC_DIR
vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

##List every .c found inside SRC_DIR
SRC =   ft_strncpy.c ft_target_strncat.c ft_toupper.c ft_str_toupper.c ft_strcchr.c \
		ft_str_fill.c ft_strncat.c ft_strsub.c ft_strnew.c ft_strnequ.c ft_strmapi.c \
		ft_strnew_c.c ft_strlcat.c ft_strchr.c ft_strcut.c ft_strequ.c ft_striteri.c \
		ft_strtok.c  ft_strdup.c  ft_strjoin.c  ft_strstr.c  ft_strnstr.c  ft_split.c  \
		ft_strlen.c  ft_strcmp.c  ft_strrchr.c  ft_strcmp_c.c  ft_strcpy.c  ft_strtrim.c \
		ft_tolower.c  ft_strcat.c  ft_strmap.c  ft_str_replace.c  ft_strncmp.c  ft_strclr.c \
		ft_striter.c  ft_strdel.c   ft_tab_dup.c  ft_tab_cpy.c  ft_sort_tab.c  ft_swap_tab.c \
		ft_tab_new.c  ft_tab_free.c  ft_tab_len.c  ft_add_to_tab.c     ft_intstr_new.c  \
		ft_intparse_tab.c  ft_inttab_new.c  ft_inttab_cpy.c   ft_swap_int.c  ft_min.c  \
		ft_max.c  ft_abs.c   ft_swap_float.c   get_next_line.c   ft_iseven.c  ft_isnum.c \
		ft_isdigit.c  ft_isalnum.c  ft_isalpha.c  ft_isprint.c  ft_isascii.c   ft_print_int_tab.c \
		ft_putchar_fd.c  ft_putinttab.c  ft_putendl_fd.c  ft_putchar.c  ft_putstr_fd.c  ft_putnbr_fd.c \
		ft_printf.c  ft_putnbr.c  ft_print_str_tab.c  ft_putendl.c  ft_putstr.c   t_flag_data.c  t_data.c \
		flag2.c  flag.c  handle_flag.c   converter3.c  converter.c  set_flags_lh.c  set_flags.c  converter2.c \
		handle_converter.c   ft_memset.c  ft_memchr.c  ft_memmove.c  ft_memccpy.c  ft_memcmp.c  ft_memalloc.c \
		ft_memdel.c  ft_memcpy.c  ft_bzero.c   ft_itoa_base.c  ft_uitoa_base.c  ft_atoi.c   ft_vector.c

##Transform and place every .o from SRC
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

##
##		COMPILER FLAGS
##

##Basics flags
CFLAGS=		-Wall -Wextra -Werror -g

##Create the flags to includes every .h needed by this program
IFLAGS =	$(foreach dir, $(INC_DIR), -I$(dir))

##Create the flags to link every libraries needed by this program (-L and -l)
LFLAGS =

##Define the compiler to use
CC=			cc

all:
				make $(NAME)


$(NAME):		$(OBJ) $(INC_DIR) Makefile
				@echo "-----\nCreating Executable $@ ... \c"
				@ar rc $(NAME) $(OBJ)
				@ranlib $(NAME)
				@echo "DONE\n-----"

$(OBJ_DIR)/%.o : %.c
				@echo "Compiling $@ ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "DONE"

clean:
				@echo "Deleting Objects Directory $(NAME) $(OBJ_DIR) ... \c"
				@rm -rf $(OBJ_DIR)
				@echo "DONE\n-----"

fclean:			clean
				@echo "Deleting Binary File $(NAME) $(NAME) ... \c"
				@rm -f $(NAME)
				@echo "DONE\n-----"

re:				fclean all

.PHONY: all clean fclean re show
