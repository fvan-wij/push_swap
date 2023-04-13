/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:13:01 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/13 16:13:50 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
	ft_putstr_fd("KO\n", STDOUT_FILENO);
	exit (EXIT_FAILURE);
}

void exit_due_operation_failure(t_meta *meta)
{
	if (meta->head_a)
		free_linked_list(&meta->head_a);
	if (meta->head_b)
		free_linked_list(&meta->head_b);
	free(meta);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
