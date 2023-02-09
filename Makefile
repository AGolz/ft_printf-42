# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 21:47:44 by emaksimo          #+#    #+#              #
#    Updated: 2023/02/09 19:46:24 by emaksimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
HEADER_B = ft_printf_bonus.h

LIBFTD = Libft/
LIBFT := ${addprefix ${LIBFTD},libft.a}
LIBFTMK = make -C $(LIBFTD)


CC = gcc
CFLAGS = -Wall -Wextra -Werror 

SOURCES = ft_pars.c ft_print_chr.c ft_print_diu.c ft_print_x.c ft_printf.c 

SOURCES_B = ft_pars_bonus.c ft_print_chr_bonus.c ft_print_diu_bonus.c ft_print_x_bonus.c ft_printf_bonus.c 

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_B = $(SOURCES_B:.c=.o)

BLUE = \033[1;36m 
PINK = \033[1;35m
RESET = \033[0m
DEFAULT = \033[0;39m

WHALE	=	"\n$(BLUE)       ::: \n     ___:____     |^\/^| \n   ,'        '.    \  / \n   |  O        \___/  | \n ~^~^~^~^~^~^~^~^~^~^~^~^~\n \n Compilation Successful!\n\n   by emaksimo for 42 \n	${NC}\n"
NUKE	=	"\n$(PINK)    _.-^^---....,,--       \n _--                  --_  \n<                        >)\n|                         | \n \._                   _./  \n    '''--. . , ; .--'''       \n          | |   |             \n       .-=||  | |=-.   \n       '-=£€%&%€£=-'   \n          | ;  :|     \n _____.,-£%&€@%£&£~,._____\n ${NC}\n"

.PHONY: all bonus clean fclean re

all: $(NAME)
	@echo $?

$(NAME): $(LIBFT) $(OBJECTS) $(HEADER)
	@echo "$(BLUE)...\n$(RESET)\c"
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJECTS) $?
	@ranlib $(NAME)
	@echo "\n$(NAME): $(BLUE) object files are created $(RESET)"
	@echo "$(NAME): $(BLUE) $(NAME) created $(RESET) $(DEFAULT)"
	@echo $(WHALE)
	
$(LIBFT):
	$(LIBFTMK)

bonus: $(LIBFT) $(OBJECTS_B) $(HEADER_B)
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJECTS_B) $?
	@echo "$(BLUE)\n  (ﾉ>ω<)ﾉ \n$(RESET)\c"
	@ranlib $(NAME)
	@echo "\n $(BLUE)｡･:*:･ﾟ’★,｡･:*:･ﾟ’☆ bonus object files are created ｡･:*:･ﾟ’★,｡･:*:･ﾟ’☆ $(RESET)" 
	@echo "\n $(BLUE)                   it's a special Street magic (─‿‿─) $(RESET)" 
	
	
clean:  
	@rm -rf $(OBJECTS) $(OBJECTS_B)
	@echo "$(PINK) ...3 2 1 $(RESET)"
	@echo $(NUKE)
	@echo "$(NAME): $(PINK) object files are deleted $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(PINK) $(NAME) deleted $(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all