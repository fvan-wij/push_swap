/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:11:10 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/28 13:24:02 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

// Linked List

typedef struct s_node
{
	int				n;
	struct s_node	*previous;
	struct s_node	*next;
}		t_node;

// Main struct

typedef struct s_meta
{
	t_node	*head_a;
	t_node	*head_b;
	int		elements_a;
	int		elements_b;
	int		operation_count;
} 		t_meta;

// Utilities
void	print_stack(t_meta *meta, t_node *head, char *stack);
void	print_reverse_stack(t_node *head, char *stack);


// Memory management
void	free_double_array(char **array);
void	free_linked_list(t_node **head);

// Sorting operations
void	rotate_stack_a(t_node *head);
void	rotate_stack_b(t_node *head);
void    rev_rotate_stack_a(t_node **head);
void    rev_rotate_stack_b(t_node **head);
void    swap_stack_a(t_node *head);
void    push_to_a(t_meta *meta, t_node **source, t_node **destination);
void    push_to_b(t_meta *meta, t_node **source, t_node **destination);

// Sorting combinations
void	push_target_to_a(t_meta *meta, int target);
void    push_target_to_b(t_meta *meta, int target);

// Sorting algorithms
void	rudimentary_sort(t_meta *meta);

