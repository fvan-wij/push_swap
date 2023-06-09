/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:34:02 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/13 12:01:27 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_stack_a(t_meta *meta, t_node *head)
{
	int	temp;

	temp = 0;
	if (!head)
		exit_due_operation_failure(meta);
	if (head && head->next)
	{
		temp = head->n;
		head->n = head->next->n;
		head->next->n = temp;
		ft_printf("sa\n");
	}
}

void	swap_stack_b(t_meta *meta, t_node *head)
{
	int	temp;

	temp = 0;
	if (!head)
		exit_due_operation_failure(meta);
	if (head->next->n && head->n)
	{
		temp = head->n;
		head->n = head->next->n;
		head->next->n = temp;
		ft_printf("sb\n");
	}
}
