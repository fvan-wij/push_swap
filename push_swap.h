/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:11:10 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/17 18:31:38 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <libft.h>
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
}	t_node;

// Main struct

typedef struct s_meta
{
	t_node	*stack_a;
	t_node	*stack_b;
} t_meta;

// Utilities

// Memory management

// Sorting operations

// Sorting algorithms
