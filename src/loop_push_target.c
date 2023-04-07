/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_push_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:12:46 by flip              #+#    #+#             */
/*   Updated: 2023/04/07 14:10:05 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_target_to_a(t_meta *meta, int target)
{
	int		i;
	int		treshold;
	t_node	*current;

	i = 0;
	treshold = meta->elements_b / 2;
	current = meta->head_b;
	while (current != NULL)
	{
		if (current->n == target && i >= treshold)
			return (rev_rotate_loop_and_push_to_a(target, meta));
		else if (current->n == target && i < treshold)
			return (rotate_loop_and_push_to_a(target, meta));
		current = current->next;
		i++;
	}
}

void	push_target_to_b(t_meta *meta, int target)
{
	int		i;
	int		treshold;
	t_node	*current;

	i = 0;
	treshold = meta->elements_a / 2;
	current = meta->head_a;
	while (current != NULL)
	{
		if (current->n == target && i >= treshold)
			return (rev_rotate_loop_and_push_to_b(target, meta));
		else if (current->n == target && i < treshold)
			return (rotate_loop_and_push_to_b(target, meta));
		current = current->next;
		i++;
	}
}
