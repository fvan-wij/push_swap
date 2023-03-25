/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:27:11 by flip              #+#    #+#             */
/*   Updated: 2023/03/25 14:41:54 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate_stack_a(t_node *head)
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

void    rev_rotate_stack_a(t_node **head) // Previous is not well linked. 
{
    t_node  *last;
    t_node  *second_last;
    
    if (*head == NULL || (*head)->next == NULL)
        return ;
    ft_printf("--> [Rev rotate a]\n");
    last = *head;
    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *head;
    *head = last;
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

    temp = *head_a;
 	ft_printf("--> [Push to a]\n");
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
        return ;
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
