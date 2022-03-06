# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/15 19:23:49 by mravily           #+#    #+#              #
#    Updated: 2022/03/06 15:26:07 by adeburea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CC =		cc

SRC_DIR = 	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d) \
			$(shell find libs/libft/includes -type d)
LIB_DIR =	libs/libft
LIBFT	=	$(LIB_DIR)/libft.a
OBJ_DIR = 	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# List de toute les library a linker au projet (le nom - le lib et - le .a)
LIB = ft readline

SRC =	cd_cmd.c echo_cmd.c env_cmd.c exit_cmd.c export_cmd.c export_utils.c \
		pwd_cmd.c unset_cmd.c builtins.c exec_cmd.c exec_utils.c here_doc.c \
		prepare_cmd.c redirect.c expansion_utils.c expansion.c parsing.c \
		process_expansion.c process_quote.c token.c \
		utils_parsing.c env.c free.c init_struct.c init.c list.c main.c \
		print_error.c print_struct.c signal.c token_utils.c utils.c \
		var_exist.c


OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

DEP = $(OBJ:.o=.d)

NORMAL_OBJ = $(OBJ)

#Compilation flag
CFLAGS = -Wall -Wextra -Werror

IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir))

LFLAGS =	$(foreach dir, $(LIB_DIR), -L $(dir)) \
			$(foreach lib, $(LIB), -l $(lib)) \

DEBUG		= -g -fsanitize=address


all:			$(NAME)

show:
				@echo "SRC :\n$(SRC)"

install:
				$(foreach dir, $(LIB_DIR), make -C $(dir) ; )

re-install:
				$(foreach dir, $(LIB_DIR), make -C $(dir) re ; )

debug: $(LIBFT) $(OBJ)
	@printf "[minishell] Compiled debug successfuly! [OK]\n"
	@$(CC) $(CFLAGS) $(LFLAGS) $(DEBUG) $(NORMAL_OBJ) -o $(NAME) $(LIBFT)

$(LIBFT):
				@make -C $(LIB_DIR)

$(NAME): 	 $(LIBFT) $(INC_DIR) $(NORMAL_OBJ)
				@echo "-----\nCreating Executable $@ ... \c"
				@$(CC) $(CFLAGS) $(LFLAGS) $(NORMAL_OBJ) -o $(NAME) $(LIBFT)
				@echo "DONE\n-----"

-include $(DEP)

$(OBJ_DIR)/%.o : %.c
				@echo "Compiling $@ ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "DONE"

norme:
				norminette $(SRC_DIR)

re:				fclean re-install all

clean-lib:
				@$(foreach dir, $(LIB_DIR), make -C $(dir) clean ; )

fclean-lib:
				@$(foreach dir, $(LIB_DIR), make -C $(dir) fclean ; )

clean:
				@echo "Deleting Objects Directory $(_RED)$(NAME) $(OBJ_DIR) ... \c"
				@rm -rf $(OBJ_DIR)
				@echo "DONE\n-----"

fclean:			clean
				@echo "Deleting Binary File $(_RED)$(NAME) $(NAME) ... \c"
				@echo "DONE\n-----"
				@rm -f $(NAME) $(BONUS_NAME)
				@$(foreach dir, $(LIB_DIR), make -C $(dir) fclean ; )

.PHONY: all clean flcean re install re-install show norme
