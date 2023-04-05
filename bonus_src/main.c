/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:50:40 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/05 18:43:25 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(void)
{
	// Read from input
	char *line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (line && ft_strncmp(line, "pa", 2) == 0)
			ft_printf("pa!!\n");
		else if (line && ft_strncmp(line, "pb", 2) == 0)
			ft_printf("pb!!\n");
		else if (line && ft_strncmp(line, "ra", 2) == 0)
			ft_printf("ra!!\n");			
		else if (line && ft_strncmp(line, "rra", 3) == 0)
			ft_printf("rra!!\n");
		else if (line && ft_strncmp(line, "sa", 2) == 0)
			ft_printf("sa!!\n");
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	
	return (0);
}
