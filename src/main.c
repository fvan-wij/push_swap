/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:10:31 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/31 18:20:21 by fvan-wij         ###   ########.fr       */
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
		meta->elements_a++;
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
	meta->elements_a = 0;
	meta->elements_b = 0;
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
	atexit(f);
	t_meta	*meta;

	meta = NULL;
	if (input_is_invalid(argv))
		return (EXIT_FAILURE);
	meta = input_to_stack(meta, argc, argv);
	if (is_sorted(meta->head_a))
	{
		ft_printf("Stack A is already sorted!\n");
		free_linked_list(&meta->head_a);
		free(meta);
		return (EXIT_SUCCESS);
	}
	radix_sort(meta);
	if (meta)
		free(meta);
	if (meta->head_a)
		free_linked_list(&meta->head_a);
	return (EXIT_SUCCESS);
}
