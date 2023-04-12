/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_push_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:26:19 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/12 18:48:11 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_loop_and_push_index_to_b(int index, t_meta *meta)
{
	while (meta->head_a->index != index)
		rotate_stack_a(meta->head_a);
	if (meta->head_a->index == index)
		push_to_b(meta, &meta->head_a, &meta->head_b);
}

void	rev_rotate_loop_and_push_index_to_b(int index, t_meta *meta)
{
	while (meta->head_a->index != index)
		rev_rotate_stack_a(&meta->head_a);
	if (meta->head_a->index == index)
		push_to_b(meta, &meta->head_a, &meta->head_b);
}

void	push_index_to_b(t_meta *meta, int index)
{
	int		i;
	int		treshold;
	t_node	*current;

	i = 0;
	treshold = meta->elements_a / 2;
	current = meta->head_a;
	while (current != NULL)
	{
		if (current->index == index && i >= treshold)
			return (rev_rotate_loop_and_push_index_to_b(index, meta));
		else if (current->index == index && i < treshold)
			return (rotate_loop_and_push_index_to_b(index, meta));
		current = current->next;
		i++;
	}
}
