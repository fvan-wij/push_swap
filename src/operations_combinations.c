/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_combinations.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: flip <flip@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 20:12:46 by flip          #+#    #+#                 */
/*   Updated: 2023/03/27 21:00:32 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
