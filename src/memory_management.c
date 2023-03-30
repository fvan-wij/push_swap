/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:48:01 by flip              #+#    #+#             */
/*   Updated: 2023/03/30 13:49:33 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_double_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_linked_list(t_node **head)
{
	t_node	*current;
	t_node	*previous;

	current = NULL;
	previous = NULL;
	current = *head;
	while (current != NULL)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	// if (head)
	// 	free(head);
}
