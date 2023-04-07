/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:50:40 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/07 18:07:13 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// void f(void)
// {
// 	system("Leaks a.out");
// }

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

void	read_instructions(t_meta *meta)
{
	char *line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (line && ft_strncmp(line, "pa", 2) == 0)
		{
			push_to_a(meta, &meta->head_b, &meta->head_a);
			ft_putstr_fd("pa\n", STDERR_FILENO);
		}
		else if (line && ft_strncmp(line, "pb", 2) == 0)
		{
			push_to_b(meta, &meta->head_a, &meta->head_b);
			ft_putstr_fd("pb\n", STDERR_FILENO);
		}
		else if (line && ft_strncmp(line, "ra", 2) == 0)
		{
			rotate_stack_a(meta->head_a);
			ft_putstr_fd("ra\n", STDERR_FILENO);
		}
		else if (line && ft_strncmp(line, "rb", 2) == 0)
		{
			rotate_stack_b(meta->head_b);
			ft_putstr_fd("rb\n", STDERR_FILENO);
		}
		else if (line && ft_strncmp(line, "rra", 3) == 0)
		{
			rev_rotate_stack_a(&meta->head_a);
			ft_putstr_fd("rra\n", STDERR_FILENO);
		}
		else if (line && ft_strncmp(line, "rrb", 3) == 0)
		{
			rev_rotate_stack_b(&meta->head_b);
			ft_putstr_fd("rrb\n", STDERR_FILENO);
		}
		else if (line && ft_strncmp(line, "sa", 2) == 0)
		{
			swap_stack_a(meta->head_a);
			ft_putstr_fd("sa\n", STDERR_FILENO);
		}
		else if (line && ft_strncmp(line, "sb", 2) == 0)
		{
			swap_stack_b(meta->head_b);
			ft_putstr_fd("sb\n", STDERR_FILENO);
		}
		else if (line && ft_strncmp(line, "ss", 2) == 0)
		{
			swap_a_and_b(meta->head_a, meta->head_b);
			ft_putstr_fd("ss\n", STDERR_FILENO);
		}
		else if (line && ft_strncmp(line, "rr", 2) == 0)
		{
			rotate_a_and_b(meta->head_a, meta->head_b);
			ft_putstr_fd("rr\n", STDERR_FILENO);
		}
		else if (line && ft_strncmp(line, "rrr", 2) == 0)
		{
			rev_rotate_a_and_b(&meta->head_a, &meta->head_b);
			ft_putstr_fd("rrr\n", STDERR_FILENO);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv)
{
	t_meta	*meta;

	meta = NULL;
	if (input_is_invalid(argv) || argc < 2)
		exit_with_error_code(meta, INVALID_INPUT);
	meta = input_to_stack(meta, argc, argv);
	read_instructions(meta);
	if (!is_sorted(meta->head_a))
		exit_ko(meta);
	else
	{
		ft_putstr_fd("OK\n", STDERR_FILENO);
		return (free_memory(meta), EXIT_SUCCESS);
	}
}
