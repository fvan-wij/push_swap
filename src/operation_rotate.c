/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:31:11 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/07 14:20:15 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stack_a(t_node *head)
{
	t_node	*current;
	int		temp_n;
	int		temp_index;

	if (!head)
		return ;
	ft_printf("ra\n");
	current = head;
	temp_n = head->n;
	temp_index = head->index;
	while (current->next != NULL)
	{
		current->n = current->next->n;
		current->index = current->next->index;
		current = current->next;
	}
	if (current->next == NULL)
	{
		current->n = temp_n;
		current->index = temp_index;
	}
}

void	rotate_stack_b(t_node *head)
{
	t_node	*current;
	int		temp;

	if (!head)
		return ;
	ft_printf("rb\n");
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
