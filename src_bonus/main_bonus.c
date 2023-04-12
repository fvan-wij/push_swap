/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:50:40 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/12 18:45:03 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	read_instructions(t_meta *meta)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (check_input(line) == -1)
		{
			if (meta->head_a)
				free_linked_list(&meta->head_a);
			if (meta->head_b)
				free_linked_list(&meta->head_b);
			free(meta);
			free(line);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		perform_operation(meta, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv)
{
	t_meta	*meta;

	meta = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (input_is_invalid(argv))
		exit_with_error_code(meta, INVALID_INPUT);
	meta = input_to_stack(meta, argc, argv);
	read_instructions(meta);
	if (!is_sorted(meta->head_a))
		exit_ko(meta);
	else if (is_sorted(meta->head_a) && meta->elements_b == 0)
	{
		ft_putstr_fd("OK\n", STDOUT_FILENO);
		return (free_memory(meta), EXIT_SUCCESS);
	}
}
