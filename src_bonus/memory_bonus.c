/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:09:07 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/13 16:12:58 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	free_double_array(char **array)
{
	int	i;

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
}

void	free_memory(t_meta *meta)
{
	if (meta->head_a)
		free_linked_list(&meta->head_a);
	if (meta->head_b)
		free_linked_list(&meta->head_b);
	free(meta);
}
