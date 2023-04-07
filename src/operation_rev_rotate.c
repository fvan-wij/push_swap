/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:32:45 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/07 14:18:44 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate_stack_a(t_node **head)
{
	t_node	*current;
	int		temp;

	temp = 0;
	if (!*head || (*head)->next == NULL)
		return ;
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
	ft_printf("rra\n");
}

void	rev_rotate_stack_b(t_node **head)
{
	t_node	*current;
	int		temp;

	temp = 0;
	if (!*head || (*head)->next == NULL)
		return ;
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
	ft_printf("rrb\n");
}
