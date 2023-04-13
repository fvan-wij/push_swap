/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:49:34 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/13 16:20:57 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	perform_push_and_rotate(t_meta *meta, char *line)
{
	if (ft_strncmp(line, "pa", 2) == 0)
	{
		push_to_a(meta, &meta->head_b, &meta->head_a);
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	}
	else if (ft_strncmp(line, "pb", 2) == 0)
	{
		push_to_b(meta, &meta->head_a, &meta->head_b);
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
	else if (ft_strncmp(line, "ra", 2) == 0)
	{
		rotate_stack_a(meta, meta->head_a);
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	}
	else if (ft_strncmp(line, "rb", 2) == 0)
	{
		rotate_stack_b(meta, meta->head_b);
		ft_putstr_fd("rb\n", STDOUT_FILENO);
	}
	else if (ft_strncmp(line, "rr", 2) == 0)
	{
		rotate_a_and_b(meta, meta->head_a, meta->head_b);
		ft_putstr_fd("rr\n", STDOUT_FILENO);
	}
}

void	perform_rev_rotate(t_meta *meta, char *line)
{
	if (ft_strncmp(line, "rra", 3) == 0)
	{
		rev_rotate_stack_a(meta, &meta->head_a);
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	}
	else if (ft_strncmp(line, "rrb", 3) == 0)
	{
		rev_rotate_stack_b(meta, &meta->head_b);
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	}
	else if (ft_strncmp(line, "rrr", 3) == 0)
	{
		rev_rotate_a_and_b(meta, &meta->head_a, &meta->head_b);
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
	}
}

void	perform_swap(t_meta *meta, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
	{
		swap_stack_a(meta, meta->head_a);
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	}
	else if (ft_strncmp(line, "sb", 2) == 0)
	{
		swap_stack_b(meta, meta->head_b);
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	}
	else if (ft_strncmp(line, "ss", 2) == 0)
	{
		swap_a_and_b(meta, meta->head_a, meta->head_b);
		ft_putstr_fd("ss\n", STDOUT_FILENO);
	}
}

void	perform_operation(t_meta *meta, char *line)
{
	if (ft_strlen(line) == 3)
	{
		perform_push_and_rotate(meta, line);
		perform_swap(meta, line);
	}
	else if (ft_strlen(line) == 4)
	{
		perform_rev_rotate(meta, line);
	}
}
