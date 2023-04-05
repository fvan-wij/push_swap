/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:17:31 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/05 17:10:36 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_alhpabetical_input(char **argv, int i, int k)
{
	while (argv[i][k])
	{
		if (argv[i][k] == '-')
			k++;
		if (!ft_isdigit(argv[i][k]))
			return (1);
		k++;
	}
	return (0);
}

int check_duplicates(char **argv, int i, int j)
{
	while (argv[j])
	{
		if (i != j && ft_strncmp(argv[i], argv[j], 11) == 0)
			return (1);
		j++;
	}
	return (0);
}

int	input_is_invalid(char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 2;
	k = 0;
	while (argv[i])
	{
		j = 1;
		k = 0;
		if (check_duplicates(argv, i, j))
			return (1);
		if (check_alhpabetical_input(argv, i, k))
			return (1);
		i++;
	}
	return (0);
}

int	is_sorted(t_node *head)
{
	t_node	*current;

	current = head;
	while (current->next != NULL)
	{
		current = current->next;
		if (current->n < current->previous->n)
			return (0);
	}
	return (1);
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
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (EXIT_SUCCESS);
	}
}
