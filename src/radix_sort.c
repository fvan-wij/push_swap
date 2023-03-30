/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:25:34 by flip              #+#    #+#             */
/*   Updated: 2023/03/30 18:56:15 by fvan-wij         ###   ########.fr       */
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
    while (current != NULL)
    {
        while (runner != NULL)
        {
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

int	find_highest_number(int	elements, t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->index == (elements - 1))
			return (current->n);
		current = current->next;
	}
	return (0);
}

int	ft_bitlen(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n>>1;
		i++;
	}
	return (i);
}

void	radix_sort(t_meta *meta)
{
	int		highest_n;
	int		bitlen;
	
	sort_index(meta);
	highest_n = find_highest_number(meta->elements_a, meta->head_a);
	bitlen = ft_bitlen(highest_n);

	int i = 100;
	int	t = 0;
	while (i >= 0)
	{
		t = i;
		ft_printf("Before: %d, after: %d\n", i, t>>2);
		i--;
	}
}
