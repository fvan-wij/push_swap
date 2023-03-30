/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:10:31 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/30 12:11:43 by flip             ###   ########.fr       */
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
		meta->elements_a++;
		i++;
	}
}

int	check_alhpabetical_input(char **input_array, t_meta *meta)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (input_array[i])
	{
		j = 0;
		while (input_array[i][j])
		{
			if (ft_isalpha(input_array[i][j]))
			{
				ft_printf("Error, input contains one or more characters.\n");
				free_double_array(input_array);
				free(meta);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicates(char **argv)
{
	int	i;
	int	j;

	
	i = 1;
	j = 2;
	while (argv[i])
	{
		while (argv[j])
		{
			if (i != j && ft_strncmp(argv[i], argv[j], 11) == 0)
			{
				ft_printf("argv[%d]: %s, argv[%d]: %s\n", i, argv[i], j, argv[j]);
				ft_printf("Error, input contains duplicates.\n");
				return (1);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
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
		check_alhpabetical_input(input_array, meta);
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
	if (check_duplicates(argv))
		return (EXIT_FAILURE);
	meta = input_to_stack(meta, argc, argv);
	
	// push_to_b(meta, &meta->head_a, &meta->head_b);
	// push_to_a(meta, &meta->head_b, &meta->head_a);
	// rotate_stack_b(meta->head_b);
	// rev_rotate_stack_a(&meta->head_a);
	print_stack(meta, meta->head_a, "Stack a");
	// print_stack(meta, meta->head_b, "Stack b");
	
	// rudimentary_sort(meta);
	// sort_index(meta);
	// print_index(meta);
	if (meta)
		free(meta);
	return (EXIT_SUCCESS);
}
