/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rudimentary_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:04:15 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/28 13:24:27 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_smallest_number(t_meta *meta)
{
	t_node	*current;
	int		smallest_number;

	current = meta->head_a;
	smallest_number = current->n;
	while(current->next != NULL)
	{
		current = current->next;
		if (current->n < smallest_number)
			smallest_number = current->n;
	}
	return (smallest_number);
}

void	rudimentary_sort(t_meta *meta)
{
	t_node	*current;
	int		target;
	
	current = meta->head_a;
	while (meta->head_a)
	{
		target = find_smallest_number(meta);
		push_target_to_b(meta, target);
	}
	while (meta->head_b)
		push_to_a(meta, &meta->head_b, &meta->head_a);
}
