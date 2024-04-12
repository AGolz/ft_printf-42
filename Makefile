# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 21:47:44 by emaksimo          #+#    #+#              #
#    Updated: 2023/02/16 17:47:34 by emaksimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCD = include/
HEADER = include/ft_printf.h
HEADER_B = include/ft_printf_bonus.h

LIBFTD = libft/
LIBFT := ${addprefix ${LIBFTD},libft.a}
LIBFTMK = make -C $(LIBFTD)


CFLAGS = -Wall -Wextra -Werror

SRSD = srcs/
OBJD = objects/

SOURCES = ft_pars.c ft_print_chr.c ft_print_diu.c ft_print_x.c ft_printf.c 

SRSD_B = srcs_bonus/
OBJD_B = objects_bonus/

SOURCES_B = ft_pars_bonus.c ft_print_chr_bonus.c ft_print_diu_bonus.c ft_print_x_bonus.c ft_printf_bonus.c 

OBJECTS := ${addprefix ${OBJD},${SOURCES:.c=.o}}
SOURCES := ${addprefix ${SRCD},${SOURCES:.c=.o}}

OBJECTS_B := ${addprefix ${OBJD_B},${SOURCES_B:.c=.o}}
SOURCES_B := ${addprefix ${SRCD_B},${SOURCES_B:.c=.o}}

BLUE = \033[1;36m 
PINK = \033[1;35m
RESET = \033[0m

WHALE	=	"\n$(BLUE)       ::: \n     ___:____     |^\/^| \n   ,'        '.    \  / \n   |  O        \___/  | \n ~^~^~^~^~^~^~^~^~^~^~^~^~\n \n Compilation Successful!\n\n   by emaksimo for 42 \n	${NC}\n"
NUKE	=	"\n$(PINK)    _.-^^---....,,--       \n _--                  --_  \n<                        >)\n|                         | \n \._                   _./  \n    '''--. . , ; .--'''       \n          | |   |             \n       .-=||  | |=-.   \n       '-=£€%&%€£=-'   \n          | ;  :|     \n _____.,-£%&€@%£&£~,._____\n ${NC}\n"
 

all: $(NAME)
	@echo $?

$(NAME): $(LIBFT) $(OBJECTS) $(HEADER)
	@echo "$(BLUE)...\n$(RESET)\c"
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJECTS) $?
	@ranlib $(NAME)
	@echo "\n$(NAME): $(BLUE) object files are created $(RESET)"
	@echo "$(NAME): $(BLUE) $(NAME) created $(RESET)"
	@echo $(WHALE)

$(OBJD)%.o: $(SRSD)%.c
	mkdir -p $(OBJD)
	$(CC) -c -o $@ $(CFLAGS) -I$(INCD) -I$(LIBFTD) $?
	
$(LIBFT):
	$(LIBFTMK)

bonus: $(LIBFT) $(OBJECTS_B) $(HEADER_B)
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJECTS_B) $?
	@echo "$(BLUE)\n  (ﾉ>ω<)ﾉ \n$(RESET)\c"
	@ranlib $(NAME)
	@echo "\n $(BLUE)｡･:*:･ﾟ’★,｡･:*:･ﾟ’☆ bonus object files are created ｡･:*:･ﾟ’★,｡･:*:･ﾟ’☆ $(RESET)" 
	@echo "\n $(BLUE)                   it's a special Street magic (─‿‿─) $(RESET)" 
	
$(OBJD_B)%.o: $(SRSD_B)%.c
	mkdir -p $(OBJD_B)
	$(CC) -c -o $@ $(CFLAGS) -I$(INCD) -I$(LIBFTD) $?

test: all
	@$(CC) -lftprintf -L. main_test.c
	@./a.out leaks_test
	@rm -f main.o a.out
	@echo "\n$(NAME): $(BLUE) test complete $(RESET)"
	@rm -rf a.out
	
 
test_b: bonus
	@$(CC) -lftprintf -L. main_test_b.c
	@./a.out leaks_test
	@rm -f main.o a.out
	@echo "\n$(NAME): $(BLUE) test bonus complete $(RESET)"
	@rm -rf a.out
	
clean:  
	@rm -rf $(OBJD) $(OBJD_B)
	@$(LIBFTMK) clean 
	@echo "$(PINK) clean libft  $(RESET)"
	@echo "$(PINK) ...3 2 1 $(RESET)"
	@echo $(NUKE)
	@echo "$(NAME): $(PINK) object files are deleted $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(LIBFTMK) fclean 
	@echo "$(PINK) fclean libft $(RESET)"
	@echo "$(NAME): $(PINK) $(NAME) deleted $(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all bonus test test_b clean fclean re
