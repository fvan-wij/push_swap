/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:36:33 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/12 18:45:10 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
		if (!append_node(&meta->head_a,
				ft_atoi_overflow(meta, meta->input_array[i])))
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

int	check_input(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != 'p' && line[i] != 'a' && line[i] != 'b'
			&& line[i] != 'r' && line[i] != 's')
			return (-1);
		i++;
	}
	return (1);
}
