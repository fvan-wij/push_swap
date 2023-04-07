/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:35:15 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/07 12:57:54 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    rev_rotate_stack_a(t_node **head)
{
    t_node  *current;
    int     temp;

    temp = 0;
    if (!*head || (*head)->next == NULL)
        return ;
    current = *head;
    while (current->next != NULL)
        current = current->next;
    temp = current->n;
    current->previous->next = NULL;
    current->previous = NULL;
    current->next = *head;
    (*head)->previous = current;
    current->n = temp;
    *head = current;
}

void    rev_rotate_stack_b(t_node **head)
{
    t_node  *current;
    int     temp;

    temp = 0;
    if (!*head || (*head)->next == NULL)
        return ;
    current = *head;
    while (current->next != NULL)
        current = current->next;
    temp = current->n;
    current->previous->next = NULL;
    current->previous = NULL;
    current->next = *head;
    (*head)->previous = current;
    current->n = temp;
    *head = current;
}

void	rev_rotate_a_and_b(t_node **head_a, t_node **head_b)
{
	rev_rotate_stack_a(head_a);
	rev_rotate_stack_b(head_b);
}
