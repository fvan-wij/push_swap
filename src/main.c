/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:10:31 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/17 18:59:54 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(void)
{
	t_meta	*meta;
	t_node	*stack_a;
	t_node	*stack_b;

	meta = malloc(sizeof(t_meta));
	stack_a = malloc(sizeof(t_node));
	stack_b = malloc(sizeof(t_node));
	meta->stack_a = stack_a;
	meta->stack_b = stack_b;
	
	stack_a->next = stack_b;
	stack_a->n = 42;
	stack_a->previous = NULL;
	stack_b->previous = stack_a;
	stack_b->n = 21;
	stack_b->next = NULL;
	
	t_node *current;

	current = stack_b;
	while (current)
	{
		ft_printf("current n: %d\n", current->n);
		current = current->previous;
	}
	return (0);
}
