/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: flip <flip@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/19 16:49:10 by flip          #+#    #+#                 */
/*   Updated: 2023/03/27 20:00:31 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		ft_printf("Number in node[%d] is %d\n", i, current->n);
		current = current->next;
		i++;
	}
	ft_printf("Total elements_a: %d, total elements_b: %d\n", meta->elements_a, meta->elements_b);
	ft_printf("\n");
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
	while(current != NULL)
	{
		ft_printf("(Reverse) Number is %d\n", current->n);
		current = current->previous;
	}
	ft_printf("\n");
}
