/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:15:19 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/05 13:22:59 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack_of_three(t_meta *meta)
{
	int	n1 = meta->head_a->index;
	int	n2 = meta->head_a->next->index;
	int	n3 = meta->head_a->next->next->index;
	if (n1 > n2 && n2 > n3 && n3 < n1)
	{
		rotate_stack_a(meta->head_a);
		swap_stack_a(meta->head_a);
	}
	else if (n1 > n2 && n2 < n3 && n3 < n1)
		rotate_stack_a(meta->head_a);
	else if (n1 > n2 && n2 < n3 && n3 > n1)
		swap_stack_a(meta->head_a);
	else if (n1 < n2 && n2 > n3 && n3 < n1)
		rev_rotate_stack_a(&meta->head_a);
	else 
	{
		rev_rotate_stack_a(&meta->head_a);
		swap_stack_a(meta->head_a);
	}
}

void	sort_stack_of_four_or_five(t_meta *meta)
{
	int i;
	i = 0;
	while (meta->elements_a != 3)
	{
		push_index_to_b(meta, i);
		i++;
	}
	sort_stack_of_three(meta);
	while (meta->elements_b != 0)
	{
		while (meta->head_b)
			push_to_a(meta, &meta->head_b, &meta->head_a);
		if (!is_sorted(meta->head_a))
			swap_stack_a(meta->head_a);
	}
}

void	sort_small_stack(t_meta *meta)
{
	sort_index(meta);
	if (meta->elements_a == 2 && !is_sorted(meta->head_a))
		rotate_stack_a(meta->head_a);
	else if (meta->elements_a == 3 && !is_sorted(meta->head_a))
		sort_stack_of_three(meta);
	else if ((meta->elements_a == 5 || meta->elements_a == 4) && !is_sorted(meta->head_a))
		sort_stack_of_four_or_five(meta);
}

