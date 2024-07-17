/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:55:58 by acoste            #+#    #+#             */
/*   Updated: 2024/07/17 15:10:00 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->before = NULL;
	return (node);
}

void	ft_lstadd_end(t_list **head, t_list *node)
{
	t_list *tail;

	if (*head == NULL)
	{
		*head = node;
		node->next = node;
		node->before = node;
	}
	else
	{
		node->next = *head;
		tail = (*head)->before;
		(*head)->before = node;
		node->before = tail;
		tail->next = node;
	}
}

void	ft_lstadd_start(t_list **head, t_list *node)
{
	t_list	*tail;

	if (*head == NULL)
	{
		*head = node;
		node->next = node;
		node->before = node;
	}
	else
	{
		tail = (*head)->before;
		tail->next = node;
		node->next = *head;
		node->before = tail;
		(*head)->before = node;
		*head = node;
	}
}

void	free_stack(t_list *head)
{
	t_list *current;
	t_list *liberation;

	if (head == NULL)
		return;
	current = head;
	head = head->next;
	while (head != current)
	{
		liberation = head;
		head = head->next;
		free(liberation);
	}
	free(head);
}

