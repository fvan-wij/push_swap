/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:34:56 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/13 16:19:24 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	swap_stack_a(t_meta *meta, t_node *head)
{
	int	temp;

	temp = 0;
	if (head && head->next)
	{
		temp = head->n;
		head->n = head->next->n;
		head->next->n = temp;
	}
	else
		exit_due_operation_failure(meta);
}

void	swap_stack_b(t_meta *meta, t_node *head)
{
	int	temp;

	if (head->next->n && head->n)
	{
		temp = head->n;
		head->n = head->next->n;
		head->next->n = temp;
	}
	else
		exit_due_operation_failure(meta);
}

void	swap_a_and_b(t_meta *meta, t_node *head_a, t_node *head_b)
{
	swap_stack_a(meta, head_a);
	swap_stack_b(meta, head_b);
}
