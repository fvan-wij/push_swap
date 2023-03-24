/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:27:11 by flip              #+#    #+#             */
/*   Updated: 2023/03/24 16:09:23 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate_stack_a(t_node *head) // Top should go to bottom!
{
	t_node *current;
	int		temp;

    ft_printf("--> [Rotate a]\n");
	current = head;
    temp = head->n;
	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}
	if (current->next == NULL)
		current->n = temp;
}

void    rev_rotate_stack_a(t_node *head, t_node *tail) // Bottom should go to top!
{
    int temp;

    ft_printf("--> [Rev rotate a]\n");
    temp = 0;
    temp = head->n;
    head->n = tail->n;
    tail->n = temp;
}

void    rotate_stack_b(t_node *head)
{
	t_node *current;
	int		temp;

    ft_printf("--> [Rotate b]\n");
	current = head;
    temp = head->n;
	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}
	if (current->next == NULL)
		current->n = temp;
}

void    swap_stack_a(t_node *head)
{
    int temp;

    if (head->next->n && head->n)
    {
        temp = head->n;
        head->n = head->next->n;
        head->next->n = temp;
        ft_printf("--> [Swap a]\n");
    }
}

void    swap_stack_b(t_node *head)
{
    int temp;

    if (head->next->n && head->n)
    {
        temp = head->n;
        head->n = head->next->n;
        head->next->n = temp;
        ft_printf("--> [Swap b]\n");
    }
}

void    push_to_a(t_node **head_b, t_node **head_a)
{
    t_node  *temp;
    if (!*head_b)
        return ;
 	ft_printf("--> [Push to a]\n");
    temp = *head_a;
	if (!*head_a)
	{
		temp = *head_b;
		*head_b = (*head_b)->next;
		*head_a = temp;
		(*head_a)->next = NULL;
		return ;
	}
    *head_a = (*head_a)->next;
    if (!*head_b)
    {
        *head_b = temp;
        (*head_b)->next = NULL;
    }
    else
    {
        temp->next = *head_b;
        (*head_b)->previous = temp;
        *head_b = temp;
    }
}

void    push_to_b(t_node **head_a, t_node **head_b)
{
    t_node  *temp;

    if (!*head_a)
	{
		ft_printf("HUH?\n");
        return ;
	}
    temp = *head_a;
    ft_printf("--> [Push to b]\n");
	if (!*head_b)
	{
		temp = *head_a;
		*head_a = (*head_a)->next;
		*head_b = temp;
		(*head_b)->next = NULL;
		return ;
	}
    *head_a = (*head_a)->next;
    if (!*head_b)
    {
        *head_b = temp;
        (*head_b)->next = NULL;
    }
    else
    {
        temp->next = *head_b;
        (*head_b)->previous = temp;
        *head_b = temp;
    }
}
