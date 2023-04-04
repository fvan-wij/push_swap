/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:25:34 by flip              #+#    #+#             */
/*   Updated: 2023/04/04 14:01:22 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
        // ft_printf("current->n: %d, is now index: %d\n", current->n, current->index);
        current = current->next;
        runner = meta->head_a;
        i = 0;
    }
}

int	find_highest_index(int	elements, t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->index == (elements - 1))
			return (current->index);
		current = current->next;
	}
	return (0);
}

size_t	ft_bitlen(size_t n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n>>1;
		i++;
	}
	return (i);
}

size_t	ft_putbit(size_t n)
{
	int		i;
	int		remainder;
	char	bits[32];
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		write(1, "0", 1);
	while (n != 0)
	{
		remainder = n % 2;
		if (remainder == 0)
			bits[i] = '0';
		else if (remainder == 1)
			bits[i] = '1';
		n = n / 2;
		i++;
	}
	while (i != 0)
	{
		count += write(1, &bits[i - 1], 1);
		i--;
	}
	write(1, "\n", 1);
	return (count);
}

void	radix_sort(t_meta *meta)
{
	int		i;
	int 	j;
	int		temp;
	int		stack_size;

	i = 0;
	temp = 0;
	stack_size = meta->elements_a;
	sort_index(meta);
	while (!is_sorted(meta->head_a))
	{
		j = 0;
		while (j < stack_size)
		{
			temp = meta->head_a->index;
			if (((temp>>i)&1) == 1)
				rotate_stack_a(meta->head_a);
			else
				push_to_b(meta, &meta->head_a, &meta->head_b);
			j++;
		}
		while (meta->head_b)
			push_to_a(meta, &meta->head_b, &meta->head_a);
		i++;
	}
}
