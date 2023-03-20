/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:11:10 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/20 08:50:07 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
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
	t_node	*tail_a;
	t_node	*tail_b;
} 		t_meta;

// Utilities
void	print_stack(t_node *head, char *stack);
void	print_reverse_stack(t_node *tail, char *stack);


// Memory management
void	free_double_array(char **array);
void	free_linked_list(t_node **head);

// Sorting operations
void	rotate_stack_a(t_node *head, t_node *tail);
void	rotate_stack_b(t_node *head);
void    swap_stack_a(t_node *head);
void    push_b(t_node **head_a, t_node **head_b);
void    push_a(t_node **head_b, t_node **head_a);

// Sorting algorithms
