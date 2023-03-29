/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:25:34 by flip              #+#    #+#             */
/*   Updated: 2023/03/29 09:41:26 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Write a function that indexes the stack in ascending order where index[0] is the lowest number

// Check first number, if bigger than 2nd number, i++, if bigger than 3rd number i++, etc.

void    sort_index(t_meta *meta)
{
    t_node  *current;
    t_node  *runner;
    int     i;

    i = 0;
    current = meta->head_a;
    runner = meta->head_a;
    while (current->next != NULL)
    {
        while (runner->next != NULL)
        {
            if (runner->index)
                runner = runner->next;
            if (current->n > runner->n)
                i++;
            runner = runner->next;
        }
        current->index = i;
        ft_printf("current->n: %d, is now index: %d\n", current->n, current->index);
        current = current->next;
        runner = meta->head_a;
        i = 0;
    }
}
