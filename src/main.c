/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:10:31 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/05 15:45:53 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void f(void)
{
	system("Leaks push_swap");
}

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

void	add_array_to_stack(t_meta *meta)
{
	int	i;

	i = 0;
	while (meta->input_array[i])
	{
		if (!append_node(&meta->head_a, ft_atoi_overflow(meta, meta->input_array[i])))
			exit_with_error_code(meta, ALLOCATION_FAILURE);
		meta->elements_a++;
		i++;
	}
}

t_meta	*input_to_stack(t_meta *meta, int argc, char **argv)
{
	int		i;

	meta = malloc(sizeof(t_meta));
	if (!meta)
		exit (EXIT_FAILURE);
	meta->head_a = NULL;
	meta->head_b = NULL;
	meta->elements_a = 0;
	meta->elements_b = 0;
	i = 1;
	while (i != argc)
	{
		meta->input_array = ft_split(argv[i], ' ');
		if (!meta->input_array)
			exit_with_error_code(meta, SPLIT_FAILURE);
		add_array_to_stack(meta);
		free_double_array(meta->input_array);
		i++;
	}
	return (meta);
}

int	main(int argc, char **argv)
{
	// atexit(f);
	t_meta	*meta;

	meta = NULL;
	if (input_is_invalid(argv) || argc <= 2)
		exit_with_error_code(meta, INVALID_INPUT);
	meta = input_to_stack(meta, argc, argv);
	if (is_sorted(meta->head_a))
		exit_with_success(meta, SORTED);
	if (meta->elements_a <= 5)
		sort_small_stack(meta);
	else
		radix_sort(meta);
	// print_stack(meta, meta->head_a, "stack A");
	return (exit_with_success(meta, SUCCESS), EXIT_SUCCESS);
}
