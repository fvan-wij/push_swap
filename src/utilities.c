/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:49:10 by flip              #+#    #+#             */
/*   Updated: 2023/03/19 17:07:53 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_node *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack;
	while (current != NULL)
	{
		ft_printf("Number in node[%d] is %d\n", i, current->n);
		current = current->next;
		i++;
	}
}
