/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:25:34 by flip              #+#    #+#             */
/*   Updated: 2023/04/12 18:48:11 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_index(t_meta *meta)
{
	t_node	*current;
	t_node	*runner;
	int		i;

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
		current = current->next;
		runner = meta->head_a;
		i = 0;
	}
}

int	find_highest_index(int elements, t_node *head)
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

void	radix_sort(t_meta *meta)
{
	int		i;
	int		j;
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
			if (((temp >> i) & 1) == 1)
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
