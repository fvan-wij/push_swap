/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:11:10 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/19 17:06:58 by flip             ###   ########.fr       */
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
	t_node	*stack_a;
	t_node	*stack_b;
} 		t_meta;

// Utilities
void	print_stack(t_node *stack);

// Memory management
void	free_double_array(char **array);
void	free_linked_list(t_node **head);

// Sorting operations

// Sorting algorithms
