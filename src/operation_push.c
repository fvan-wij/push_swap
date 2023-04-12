/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:33:25 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/12 13:37:04 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_a(t_meta *meta, t_node **source, t_node **destination)
{
	t_node	*temp;

	if (!*source)
		return ;
	else if (!*destination)
	{
		temp = *source;
		*source = (*source)->next;
		*destination = temp;
		(*destination)->next = NULL;
		ft_printf("pa\n");
	}
	else
	{
		temp = *source;
		*source = (*source)->next;
		temp->next = *destination;
		(*destination)->previous = temp;
		*destination = temp;
		(*destination)->previous = NULL;
		ft_printf("pa\n");
	}
	meta->elements_a++;
	meta->elements_b--;
	return ;
}

void	push_to_b(t_meta *meta, t_node **source, t_node **destination)
{
	t_node	*temp;

	if (!*source)
		return ;
	else if (!*destination)
	{
		temp = *source;
		*source = (*source)->next;
		*destination = temp;
		(*destination)->next = NULL;
		ft_printf("pb\n");
	}
	else
	{
		temp = *source;
		*source = (*source)->next;
		temp->next = *destination;
		(*destination)->previous = temp;
		*destination = temp;
		(*destination)->previous = NULL;
		ft_printf("pb\n");
	}
	meta->elements_b++;
	meta->elements_a--;
	return ;
}
