/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:48:01 by flip              #+#    #+#             */
/*   Updated: 2023/04/07 17:51:28 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	exit_with_success(t_meta *meta, t_error error_code)
{
	if (error_code == SUCCESS)
	{
		free_linked_list(&meta->head_a);
		free(meta);
		exit (EXIT_SUCCESS);
	}
	else if (error_code == SORTED)
	{
		free_linked_list(&meta->head_a);
		free(meta);
		exit (EXIT_SUCCESS);
	}
}
