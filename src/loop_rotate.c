/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:29:05 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/13 12:19:09 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_loop_and_push_to_a(int target, t_meta *meta)
{
	while (meta->head_b->n != target)
		rotate_stack_b(meta, meta->head_b);
	if (meta->head_b->n == target)
		push_to_a(meta, &meta->head_b, &meta->head_a);
}

void	rotate_loop_and_push_to_b(int target, t_meta *meta)
{
	while (meta->head_a->n != target)
		rotate_stack_a(meta, meta->head_a);
	if (meta->head_a->n == target)
		push_to_b(meta, &meta->head_a, &meta->head_b);
}

void	rev_rotate_loop_and_push_to_a(int target, t_meta *meta)
{
	while (meta->head_b->n != target)
		rev_rotate_stack_b(meta, &meta->head_b);
	if (meta->head_b->n == target)
		push_to_a(meta, &meta->head_b, &meta->head_a);
}

void	rev_rotate_loop_and_push_to_b(int target, t_meta *meta)
{
	while (meta->head_a->n != target)
		rev_rotate_stack_a(meta, &meta->head_a);
	if (meta->head_a->n == target)
		push_to_b(meta, &meta->head_a, &meta->head_b);
}
