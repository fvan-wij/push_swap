# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 13:03:08 by fvan-wij          #+#    #+#              #
#    Updated: 2023/04/07 17:45:39 by fvan-wij         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap
FLAGS		:= 	-g -Wall -Wextra -Werror
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
				

SRCS_BONUS	:= 	main.c \
				push.c \
				rev_rotate.c \
				rotate.c \
				swap.c \

SRCDIR 		:= 	./src
OBJDIR 		:= 	./obj
OBJS		:= 	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS		:= 	$(addprefix $(SRCDIR)/,$(SRCS))
DEBUG		:= 	-fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	@$(CC) $^ $(LIBFT) $(HEADERS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -o $@ -c $< $(HEADERS)

clean:
	@rm -rf $(OBJDIR) $(NAME)
	@$(MAKE) -C clean
	@$(MAKE) -C libft clean

fclean:	clean
	@rm -f $(NAME)
	@$(MAKE) -C fclean
	@$(MAKE) -C libft fclean

re:	fclean all

.PHONY:	all, clean, fclean, re
