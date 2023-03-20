/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:27:11 by flip              #+#    #+#             */
/*   Updated: 2023/03/20 08:52:11 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate_stack_a(t_node *head, t_node *tail) // Work with tail and head? 
{
    int temp;

    ft_printf("--> [Rotate a]\n");
    temp = 0;
    temp = head->n;
    head->n = tail->n;
    tail->n = temp;
}

void    rotate_stack_b(t_node *head) // Or work without tail and head?
{
    t_node  *current;
    int temp;

    ft_printf("--> [Rotate b]\n");
    current = head;
    while (current->next != NULL)
        current = current->next;
    temp = current->n;
    current->n = head->n;
    head->n = temp;
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

void    push_a(t_node **head_b, t_node **head_a)
{
    t_node  *temp;

    if (!*head_a)
        return ;
    temp = *head_a;
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
    ft_printf("--> [Push b]\n");
}

void    push_b(t_node **head_a, t_node **head_b)
{
    t_node  *temp;

    if (!*head_a)
        return ;
    temp = *head_a;
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
    ft_printf("--> [Push b]\n");
}
