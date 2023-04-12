/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:10:31 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/12 15:12:27 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_meta	*meta;

	meta = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (input_is_invalid(argv))
		exit_with_error_code(meta, INVALID_INPUT);
	meta = input_to_stack(meta, argc, argv);
	if (is_sorted(meta->head_a))
		exit_with_success(meta, SORTED);
	if (meta->elements_a <= 5)
		sort_small_stack(meta);
	else
		radix_sort(meta);
	return (exit_with_success(meta, SUCCESS), EXIT_SUCCESS);
}
