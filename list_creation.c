/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:55:58 by acoste            #+#    #+#             */
/*   Updated: 2024/07/16 12:34:09 by acoste           ###   ########.fr       */
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
	}
	else
	{
		tail = (*head)->before;
		tail->next = node;
		node->next = *head;
		node->before = tail;
		(*head)->before = node;
	}
}

void	ft_lstadd_start(t_list **head, t_list *node)
{
	t_list	*tail;

	if (*head == NULL)
	{
		*head = node;
	}
	else
	{
		tail = (*head)->before;
		tail->next = node;
		node->next = *head;
		node->before = tail;
		(*head)->before = node;
		*head = node; // ? head = &node;
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
		free(liberation); // delone ?
	}
	free(head);
}

//void	delone(t_list *node)?


// comment je recup mon debut,
// je peux le stocker au debut dans une fonction
// mais comment je le change dc

