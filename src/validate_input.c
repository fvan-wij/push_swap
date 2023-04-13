/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:17:31 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/13 17:31:23 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_alhpabetical_input(char **argv, int i, int k)
{
	while (argv[i][k])
	{
		if (argv[i][k] == '-' && ft_isdigit(argv[i][k + 1]))
			k++;
		else if (!ft_isdigit(argv[i][k]) && argv[i][k] != ' ')
			return (1);
		k++;
	}
	return (0);
}

int	check_duplicates(char **argv, int i, int j)
{
	while (argv[j])
	{
		if (i != j && ft_strncmp(argv[i], argv[j], 11) == 0)
			return (1);
		j++;
	}
	return (0);
}

int	input_is_empty(char **argv, int i, int k)
{	
	if (argv[i][0] == '\0')
		return (1);
	while (argv[i][k])
	{		
		if (argv[i][k] != ' ')
			return (0);
		k++;
	}
	return (1);
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
		if (input_is_empty(argv, i, k))
			return (1);
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
