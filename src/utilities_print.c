/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:49:10 by flip              #+#    #+#             */
/*   Updated: 2023/04/12 18:48:11 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_bitlen(size_t n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n >> 1;
		i++;
	}
	return (i);
}

size_t	ft_putbit(size_t n)
{
	int		i;
	int		remainder;
	char	bits[32];
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		write(1, "0", 1);
	while (n != 0)
	{
		remainder = n % 2;
		if (remainder == 0)
			bits[i] = '0';
		else if (remainder == 1)
			bits[i] = '1';
		n = n / 2;
		i++;
	}
	while (i-- != 0)
		count += write(1, &bits[i - 1], 1);
	write(1, "\n", 1);
	return (count);
}

void	print_stack(t_meta *meta, t_node *head, char *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	current = head;
	ft_printf("--> Printing %s\n", stack);
	if (!current)
	{
		ft_printf("%s is empty\n\n", stack);
		return ;
	}
	while (current != NULL)
	{
		ft_printf("Number in node[%d] is %d, index is: %d\n",
			i, current->n, current->index);
		current = current->next;
		i++;
	}
	ft_printf("Total elements_a: %d, total elements_b: %d\n\n",
		meta->elements_a, meta->elements_b);
}

void	print_reverse_stack(t_node *head, char *stack)
{
	t_node	*current;

	current = head;
	if (!current)
	{
		ft_printf("--> Reverse printing %s\n", stack);
		ft_printf("%s is empty\n\n", stack);
		return ;
	}
	ft_printf("--> Printing reversed %s\n", stack);
	while (current->next != NULL)
		current = current->next;
	while (current != NULL)
	{
		ft_printf("(Reverse) Number is %d\n", current->n);
		current = current->previous;
	}
	ft_printf("\n");
}
