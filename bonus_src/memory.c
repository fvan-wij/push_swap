/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:09:07 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/07 18:09:45 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	exit_with_error_code(t_meta *meta, t_error error_code)
{
	if (error_code == INVALID_INPUT)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	else if (error_code == ALLOCATION_FAILURE)
	{
		free_double_array(meta->input_array);
		if (meta->head_a)
			free_linked_list(&meta->head_a);
		free(meta);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	else if (error_code == SPLIT_FAILURE)
	{
		free_double_array(meta->input_array);
		free(meta);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}

void	exit_ko(t_meta *meta)
{
	if (meta->head_a)
		free_linked_list(&meta->head_a);
	if (meta->head_b)
		free_linked_list(&meta->head_b);
	free(meta);
	ft_putstr_fd("KO\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

void	free_memory(t_meta *meta)
{
	free_linked_list(&meta->head_a);
	free(meta);
}
