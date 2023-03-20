/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:10:31 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/20 08:50:36 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*append_node(t_node **stack, int n)
{
	t_node	*current;
	t_node	*previous;
	t_node	*new_node;
	
	current = NULL;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->n = n;
	if (!*stack)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
			current->previous = previous;
		}
		current->next = new_node;
		new_node->previous = current;
	}
	return (new_node);
}

t_node	*add_array_to_stack(char **input_array, t_meta *meta)
{
	t_node	*tail;
	int	i;

	i = 0;
	while (input_array[i])
	{
		if (!(tail = append_node(&meta->head_a, ft_atoi(input_array[i]))))
		{
			free_double_array(input_array);
			free_linked_list(&meta->head_a);
			free(meta);
			ft_printf("Allocation failed\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (tail);
}

t_meta	*input_to_stack(t_meta *meta, int argc, char **argv)
{
	char	**input_array;
	int		i;

	meta = malloc(sizeof(t_meta));
	if (!meta)
		exit(EXIT_FAILURE);
	i = 1;
	while (i != argc)
	{
		input_array = ft_split(argv[i], ' ');
		meta->tail_a = add_array_to_stack(input_array, meta);
		free_double_array(input_array);
		i++;
	}
	print_stack(meta->head_a, "stack a");
	print_stack(meta->head_b, "stack b");
	push_b(&meta->head_a, &meta->head_b);
	print_stack(meta->head_a, "stack a");
	print_stack(meta->head_b, "stack b");
	push_b(&meta->head_a, &meta->head_b);
	print_stack(meta->head_a, "stack a");
	print_stack(meta->head_b, "stack b");
	push_a(&meta->head_b, &meta->head_a);
	print_stack(meta->head_a, "stack a");
	print_stack(meta->head_b, "stack b");
	rotate_stack_b(meta->head_b);
	print_stack(meta->head_a, "stack a");
	print_stack(meta->head_b, "stack b");
	return (meta);
}

int	main(int argc, char **argv)
{
	t_meta	*meta;

	meta = input_to_stack(meta, argc, argv);
	if (meta)
		free(meta);
	return (EXIT_SUCCESS);
}
