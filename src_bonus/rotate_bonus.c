/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:35:31 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/13 16:18:28 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	rotate_stack_a(t_meta *meta, t_node *head)
{
	t_node	*current;
	int		temp_n;

	if (!head)
		exit_due_operation_failure(meta);
	current = head;
	temp_n = head->n;
	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}
	if (current->next == NULL)
		current->n = temp_n;
}

void	rotate_stack_b(t_meta *meta, t_node *head)
{
	t_node	*current;
	int		temp;

	if (!head)
		exit_due_operation_failure(meta);
	current = head;
	temp = head->n;
	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}
	if (current->next == NULL)
		current->n = temp;
}

void	rotate_a_and_b(t_meta *meta, t_node *head_a, t_node *head_b)
{
	rotate_stack_a(meta, head_a);
	rotate_stack_b(meta, head_b);
}
