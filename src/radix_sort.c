/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:25:34 by flip              #+#    #+#             */
/*   Updated: 2023/03/30 20:36:09 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Write a function that indexes the stack in ascending order where index[0] is the lowest number
// Check first number, if bigger than 2nd number, i++, if bigger than 3rd number i++, etc.

void    sort_index(t_meta *meta)
{
    t_node  *current;
    t_node  *runner;
    int     i;

    i = 0;
    current = meta->head_a;
    runner = meta->head_a;
    while (current != NULL)
    {
        while (runner != NULL)
        {
            if (current->n > runner->n)
                i++;
            runner = runner->next;
        }
        current->index = i;
        ft_printf("current->n: %d, is now index: %d\n", current->n, current->index);
        current = current->next;
        runner = meta->head_a;
        i = 0;
    }
}

int	find_highest_number(int	elements, t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->index == (elements - 1))
			return (current->n);
		current = current->next;
	}
	return (0);
}

size_t	ft_bitlen(size_t n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n>>1;
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
	while (i != 0)
	{
		count += write(1, &bits[i - 1], 1);
		i--;
	}
	return (count);
}

void	radix_sort(t_meta *meta)
{
	t_node	*current;
	int		temp;
	int		i;
	int		highest_n;
	int		bitlen;
	
	sort_index(meta);
	highest_n = find_highest_number(meta->elements_a, meta->head_a);
	bitlen = ft_bitlen(highest_n);
	// ft_printf("%d\n", bitlen);
	// 000
	//   |
	//   Scan last bit
	//   	if n&1 == 1, pb
	// 		else
	// 		ra
	

	i = 0;
	temp = 0;
	current = meta->head_a;
	while (current->next != NULL)
	{
		current->index = temp;
		ft_putbit(temp);
		current = current->next;
		i++;
	}
}
