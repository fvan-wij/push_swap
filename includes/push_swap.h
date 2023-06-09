/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:11:10 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/13 12:07:08 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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
typedef enum s_error
{
	SUCCESS,
	INVALID_INPUT,
	ALLOCATION_FAILURE,
	SPLIT_FAILURE,
	SORTED,
	OPERATION_FAILURE
}	t_error;

//		Linked List
typedef struct s_node
{
	int				n;
	int				index;
	struct s_node	*previous;
	struct s_node	*next;
}		t_node;

//		Main Struct
typedef struct s_meta
{
	t_node	*head_a;
	t_node	*head_b;
	int		elements_a;
	int		elements_b;
	char	**input_array;
}		t_meta;

//===================Operations=====================
void	rotate_stack_a(t_meta *meta, t_node *head);
void	rotate_stack_b(t_meta *meta, t_node *head);
void	rev_rotate_stack_a(t_meta *meta, t_node **head);
void	rev_rotate_stack_b(t_meta *meta, t_node **head);
void	swap_stack_a(t_meta *meta, t_node *head);
void	push_to_a(t_meta *meta, t_node **source, t_node **destination);
void	push_to_b(t_meta *meta, t_node **source, t_node **destination);

//===================Loop Operations================
void	push_target_to_a(t_meta *meta, int target);
void	push_target_to_b(t_meta *meta, int target);
void	push_index_to_a(t_meta *meta, int target);
void	push_index_to_b(t_meta *meta, int target);
void	rotate_loop_and_push_index_to_b(int index, t_meta *meta);
void	rev_rotate_loop_and_push_index_to_b(int index, t_meta *meta);
void	rotate_loop_and_push_to_a(int target, t_meta *meta);
void	rotate_loop_and_push_to_b(int target, t_meta *meta);
void	rev_rotate_loop_and_push_to_a(int target, t_meta *meta);
void	rev_rotate_loop_and_push_to_b(int target, t_meta *meta);

//===================Parsing========================
int		ft_atoi_overflow(t_meta *meta, const char *nptr);
t_meta	*input_to_stack(t_meta *meta, int argc, char **argv);

//===================Sorting Algorithms=============
void	sort_index(t_meta *meta);
void	radix_sort(t_meta *meta);
void	sort_small_stack(t_meta *meta);
void	sort_stack_of_three(t_meta *meta);
void	sort_stack_of_four_or_five(t_meta *meta);

//===================Utilities======================
void	print_stack(t_meta *meta, t_node *head, char *stack);
void	print_reverse_stack(t_node *head, char *stack);
int		find_highest_index(int elements, t_node *head);
size_t	ft_bitlen(size_t n);
size_t	ft_putbit(size_t n);

//===================Memory Management==============
void	free_double_array(char **array);
void	free_linked_list(t_node **head);
void	exit_with_error_code(t_meta *meta, t_error error_code);
void	exit_with_success(t_meta *meta, t_error error_code);
void	exit_due_operation_failure(t_meta *meta);

//===================Validation=====================
int		input_is_invalid(char **argv);
int		is_sorted(t_node *head);

#endif