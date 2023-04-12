/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:34:56 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/12 18:45:23 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	swap_stack_a(t_node *head)
{
	int	temp;

	temp = 0;
	if (head && head->next)
	{
		temp = head->n;
		head->n = head->next->n;
		head->next->n = temp;
	}
}

void	swap_stack_b(t_node *head)
{
	int	temp;

	if (head->next->n && head->n)
	{
		temp = head->n;
		head->n = head->next->n;
		head->next->n = temp;
	}
}

void	swap_a_and_b(t_node *head_a, t_node *head_b)
{
	swap_stack_a(head_a);
	swap_stack_b(head_b);
}
