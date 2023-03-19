/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:48:01 by flip              #+#    #+#             */
/*   Updated: 2023/03/19 16:48:29 by flip             ###   ########.fr       */
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
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	free(head);
}
