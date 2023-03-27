/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_operations.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: flip <flip@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/19 17:27:11 by flip          #+#    #+#                 */
/*   Updated: 2023/03/27 20:03:47 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate_stack_a(t_node *head)
{
	t_node *current;
	int		temp;
    
    if (!head)
        return ;
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

void    rotate_stack_b(t_node *head)
{
	t_node *current;
	int		temp;

    if (!head)
        return ;
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
    ft_printf("--> [Rev rotate a]\n");
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
    ft_printf("--> [Rev rotate b]\n");
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

void    push_to_a(t_meta *meta, t_node **source, t_node **destination)
{
    t_node  *temp;

    if (!*source)
        return ;
	else if (!*destination)
	{
		temp = *source;
		*source = (*source)->next;
		*destination = temp;
		(*destination)->next = NULL;
        ft_printf("--> [Push to a]\n");
        meta->elements_a--;
        meta->elements_b++;
		return ;
	}
    else
    {
        temp = *source;
        *source = (*source)->next;
        temp->next = *destination;
        (*destination)->previous = temp;
        *destination = temp;
        (*destination)->previous = NULL;
        meta->elements_a--;
        meta->elements_b++;
        ft_printf("--> [Push to a]\n");
    }
}

void    push_to_b(t_meta *meta, t_node **source, t_node **destination)
{
    t_node  *temp;

    if (!*source)
        return ;
	else if (!*destination)
	{
		temp = *source;
		*source = (*source)->next;
		*destination = temp;
		(*destination)->next = NULL;
        meta->elements_b++;
        meta->elements_a--;
        ft_printf("--> [Push to b]\n");
		return ;
	}
    else
    {
        temp = *source;
        *source = (*source)->next;
        temp->next = *destination;
        (*destination)->previous = temp;
        *destination = temp;
        (*destination)->previous = NULL;
        meta->elements_b++;
        meta->elements_a--;
        ft_printf("--> [Push to b]\n");
    }
}
