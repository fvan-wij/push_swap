/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:10:31 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/25 14:33:18 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	append_node(t_node **stack, int n)
{
	t_node	*current;
	t_node	*new_node;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->n = n;
	new_node->next = NULL;
	new_node->previous = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return (1);
	}
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->previous = current;
		return (1);
	}
}

void	add_array_to_stack(char **input_array, t_meta *meta)
{
	int	i;

	i = 0;
	while (input_array[i])
	{
		if (!append_node(&meta->head_a, ft_atoi(input_array[i])))
		{
			free_double_array(input_array);
			free_linked_list(&meta->head_a);
			free(meta);
			ft_printf("Allocation failed\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

t_meta	*input_to_stack(t_meta *meta, int argc, char **argv)
{
	char	**input_array;
	int		i;

	meta = malloc(sizeof(t_meta));
	if (!meta)
		exit(EXIT_FAILURE);
	meta->head_a = NULL;
	meta->head_b = NULL;
	i = 1;
	while (i != argc)
	{
		input_array = ft_split(argv[i], ' ');
		add_array_to_stack(input_array, meta);
		free_double_array(input_array);
		i++;
	}
	return (meta);
}

int	main(int argc, char **argv)
{
	t_meta	*meta;

	meta = NULL;
	meta = input_to_stack(meta, argc, argv);
	print_stack(meta->head_a, "Stack a");
	rev_rotate_stack_a(&meta->head_a);
	print_stack(meta->head_a, "Stack a");
	rev_rotate_stack_a(&meta->head_a);
	print_stack(meta->head_a, "Stack a");
	rev_rotate_stack_a(&meta->head_a);
	print_stack(meta->head_a, "Stack a");
	rev_rotate_stack_a(&meta->head_a);
	print_reverse_stack(meta->head_a, "Stack a");
	
	if (meta)
		free(meta);
	return (EXIT_SUCCESS);
}
