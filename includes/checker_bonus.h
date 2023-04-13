/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:53:25 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/13 16:20:21 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H_BONUS
# define CHECKER_H_BONUS
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//===================Data Types=====================

//		Enumeration
typedef enum e_error
{
	SUCCESS,
	INVALID_INPUT,
	ALLOCATION_FAILURE,
	SPLIT_FAILURE,
	SORTED,
	KO
}	t_error;

//		Linked List
typedef struct s_node
{
	int				n;
	int				index;
	struct s_node	*previous;
	struct s_node	*next;
}	t_node;

//		Main Struct
typedef struct s_meta
{
	t_node	*head_a;
	t_node	*head_b;
	int		elements_a;
	int		elements_b;
	int		operation_count;
	char	**input_array;
}	t_meta;

//===================Operations=====================

//		SA/SB/SS
void	swap_stack_a(t_meta *meta, t_node *head);
void	swap_stack_b(t_meta *meta, t_node *head);
void	swap_a_and_b(t_meta *meta, t_node *head_a, t_node *head_b);

//		PA/PB
void	push_to_a(t_meta *meta, t_node **source, t_node **destination);
void	push_to_b(t_meta *meta, t_node **source, t_node **destination);

// 		RA/RB/RR
void	rotate_stack_a(t_meta *meta, t_node *head);
void	rotate_stack_b(t_meta *meta, t_node *head);
void	rotate_a_and_b(t_meta *meta, t_node *head_a, t_node *head_b);

// 		RRA/RRB/RRR
void	rev_rotate_stack_a(t_meta *meta, t_node **head);
void	rev_rotate_stack_b(t_meta *meta, t_node **head);
void	rev_rotate_a_and_b(t_meta *meta, t_node **head_a, t_node **head_b);

//===================Error Handling=================

// Input validation
int		input_is_invalid(char **argv);
int		is_sorted(t_node *head);
int		ft_atoi_overflow(t_meta *meta, const char *nptr);
int		check_input(char *line);
t_meta	*input_to_stack(t_meta *meta, int argc, char **argv);

// Memory management
void	free_double_array(char **array);
void	free_linked_list(t_node **head);
void	exit_with_error_code(t_meta *meta, t_error error_code);
void	exit_with_success(t_meta *meta, t_error error_code);
void	exit_ko(t_meta *meta);
void	free_memory(t_meta *meta);
void	exit_due_operation_failure(t_meta *meta);

//===================Read instructions==============
void	read_instructions(t_meta *meta);
void	perform_swap(t_meta *meta, char *line);
void	perform_rev_rotate(t_meta *meta, char *line);
void	perform_push_and_rotate(t_meta *meta, char *line);
void	perform_operation(t_meta *meta, char *line);

#endif