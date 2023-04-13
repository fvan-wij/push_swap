# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 13:03:08 by fvan-wij          #+#    #+#              #
#    Updated: 2023/04/13 16:14:07 by fvan-wij         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap
NAME_BONUS	:=	checker
FLAGS		:= 	-Wall -Wextra -Werror
LIBFT		:= 	./libft/libft.a
HEADERS		:= 	-I ./includes -I /include -I ./libft
SRCS		:= 	main.c \
				parse_input.c \
				parse_atoi_overflow_protection.c \
				operation_push.c \
				operation_rev_rotate.c \
				operation_rotate.c \
				operation_swap.c \
				loop_push_index.c \
				loop_push_target.c \
				loop_rotate.c \
				sort_small_stack.c \
				sort_radix.c \
				validate_input.c \
				utilities_print.c \
				memory_management.c \

SRCS_BONUS	:= 	main_bonus.c \
				push_bonus.c \
				rev_rotate_bonus.c \
				rotate_bonus.c \
				swap_bonus.c \
				ft_atoi_overflow_bonus.c \
				memory_bonus.c \
				parse_bonus.c \
				read_instructions_bonus.c \
				swap_bonus.c \
				validate_input_bonus.c \
				exit_bonus.c \

SRCDIR 		:= 	./src
OBJDIR 		:= 	./obj
OBJS		:= 	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS		:= 	$(addprefix $(SRCDIR)/,$(SRCS))

SRCDIR_BONUS:=	./src_bonus
OBJDIR_BONUS:=	./src_obj
OBJS_BONUS	:= 	$(addprefix $(OBJDIR_BONUS)/,$(SRCS_BONUS:.c=.o))
SRCS_BONUS	:= 	$(addprefix $(SRCDIR_BONUS)/,$(SRCS_BONUS))

DEBUG		:= 	-fsanitize=address

# Colors #############################################
Black		= "\033[0;30m"		# Black
Red			= "\033[0;31m"		# Red
Green		= "\033[0;32m"		# Green
Yellow		= "\033[0;33m"		# Yellow
Blue		= "\033[0;34m"		# Blue
Purple		= "\033[0;35m"		# Purple
Cyan		= "\033[0;36m"		# Cyan
White		= "\033[0;37m"		# White
Text_Off	= "\033[0m"			# Text Style Off
Bold		= "\033[1m"			# Text Style Bold
######################################################

all: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	@$(CC) $^ $(LIBFT) $(HEADERS) -o $(NAME)
	@echo $(Green) $(Bold) Push_swap ✅ $(Text_Off)

$(NAME_BONUS):	$(OBJS_BONUS)
	@$(CC) $^ $(LIBFT) $(HEADERS) -o $(NAME_BONUS)
	@echo $(Green) $(Bold) Checker ✅ $(Text_Off)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -o $@ -c $< $(HEADERS)

$(OBJDIR_BONUS)/%.o: $(SRCDIR_BONUS)/%.c
	@mkdir -p $(OBJDIR_BONUS)
	@$(CC) $(FLAGS) -o $@ -c $< $(HEADERS)

clean:
	@rm -rf $(OBJDIR) $(OBJDIR_BONUS)
	@$(MAKE) -C libft clean
	@echo $(Yellow) Cleaned object files! $(Text_Off)

fclean:	clean
	@rm -f $(NAME) $(NAME_BONUS) $(LIBFT)
	@$(MAKE) -C libft fclean
	@echo $(Yellow) Cleaned executables! $(Text_Off)

re:	fclean all

bonus:	$(NAME_BONUS)

.PHONY:	all, clean, fclean, re
