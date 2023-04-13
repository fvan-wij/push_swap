/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:35:15 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/13 16:17:45 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	rev_rotate_stack_a(t_meta *meta, t_node **head)
{
	t_node	*current;
	int		temp;

	temp = 0;
	if (!*head || (*head)->next == NULL)
		exit_due_operation_failure(meta);
	current = *head;
	while (current->next != NULL)
		current = current->next;
	temp = current->n;
	current->previous->next = NULL;
	current->previous = NULL;
	current->next = *head;
	(*head)->previous = current;
	current->n = temp;
	*head = current;
}

void	rev_rotate_stack_b(t_meta *meta, t_node **head)
{
	t_node	*current;
	int		temp;

	temp = 0;
	if (!*head || (*head)->next == NULL)
		exit_due_operation_failure(meta);
	current = *head;
	while (current->next != NULL)
		current = current->next;
	temp = current->n;
	current->previous->next = NULL;
	current->previous = NULL;
	current->next = *head;
	(*head)->previous = current;
	current->n = temp;
	*head = current;
}

void	rev_rotate_a_and_b(t_meta *meta, t_node **head_a, t_node **head_b)
{
	rev_rotate_stack_a(meta, head_a);
	rev_rotate_stack_b(meta, head_b);
}
