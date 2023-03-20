/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:49:10 by flip              #+#    #+#             */
/*   Updated: 2023/03/20 08:38:46 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_node *head, char *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	current = head;
	ft_printf("--> Printing %s\n", stack);
	if (!current)
	{
		ft_printf("%s is empty\n\n", stack);
		return ;
	}
	while (current != NULL)
	{
		ft_printf("Number in node[%d] is %d\n", i, current->n);
		current = current->next;
		i++;
	}
	ft_printf("\n");
}

void	print_reverse_stack(t_node *tail, char *stack)
{
	t_node	*current;
	
	current = tail;
	ft_printf("--> Printing reversed %s\n", stack);
	while (current != NULL)
	{
		ft_printf("(Reverse) Number is %d\n", current->n);
		current = current->previous;
	}
	ft_printf("\n");
}
