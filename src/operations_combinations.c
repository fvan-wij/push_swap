/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_combinations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:12:46 by flip              #+#    #+#             */
/*   Updated: 2023/04/04 17:29:15 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate_loop_and_push_to_a(int target, t_meta *meta)
{
    while (meta->head_b->n != target)
        rotate_stack_b(meta->head_b);
    if (meta->head_b->n == target)
        push_to_a(meta, &meta->head_b, &meta->head_a);
}

void    rev_rotate_loop_and_push_to_a(int target, t_meta *meta)
{
    while (meta->head_b->n != target)
        rev_rotate_stack_b(&meta->head_b);
    if (meta->head_b->n == target)
        push_to_a(meta, &meta->head_b, &meta->head_a);
}

void    rotate_loop_and_push_to_b(int target, t_meta *meta)
{
    while (meta->head_a->n != target)
        rotate_stack_a(meta->head_a);
    if (meta->head_a->n == target)
        push_to_b(meta, &meta->head_a, &meta->head_b);
}

void    rev_rotate_loop_and_push_to_b(int target, t_meta *meta)
{
    while (meta->head_a->n != target)
        rev_rotate_stack_a(&meta->head_a);
    if (meta->head_a->n == target)
        push_to_b(meta, &meta->head_a, &meta->head_b);
}

void	push_target_to_a(t_meta *meta, int	target)
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

void    push_target_to_b(t_meta *meta, int target)
{   
    int     i;
    int     treshold;
    t_node  *current;
    
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


void    rotate_loop_and_push_index_to_b(int index, t_meta *meta)
{
    while (meta->head_a->index != index)
        rotate_stack_a(meta->head_a);
    if (meta->head_a->index == index)
        push_to_b(meta, &meta->head_a, &meta->head_b);
}

void    rev_rotate_loop_and_push_index_to_b(int index, t_meta *meta)
{
    while (meta->head_a->index != index)
        rev_rotate_stack_a(&meta->head_a);
    if (meta->head_a->index == index)
        push_to_b(meta, &meta->head_a, &meta->head_b);
}

void    push_index_to_b(t_meta *meta, int index)
{   
    int     i;
    int     treshold;
    t_node  *current;
    
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
