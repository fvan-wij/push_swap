# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fvan-wij <fvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/16 13:03:08 by fvan-wij      #+#    #+#                  #
#    Updated: 2023/03/27 20:32:26 by flip          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
FLAGS		:= -Wall -Wextra # -Werror
LIBFT		:= ./libft/libft.a
HEADERS		:= -I ./includes -I /include -I ./libft
SRCS		:= 	main.c \
				memory_management.c \
				sorting_operations.c \
				operations_combinations.c \
				utilities.c \

SRCDIR 		:= ./src
OBJDIR 		:= ./obj
OBJS		:= $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS		:= $(addprefix $(SRCDIR)/,$(SRCS))
DEBUG		:= -fsanitize=address
# **************************************************************************** #

# ifdef DEBUG
# 		FLAGS += -g -fsanitize=address
# endif

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
