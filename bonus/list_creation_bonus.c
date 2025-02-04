/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:51:09 by acoste            #+#    #+#             */
/*   Updated: 2024/07/30 02:00:35 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

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
	t_list	*tail;

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

int	stack_lenght(t_list *head)
{
	int		i;
	t_list	*trace;

	if (head == NULL)
		return ('0');
	i = 0;
	trace = head;
	trace = trace->next;
	while (trace->next != NULL && trace != head)
	{
		i++;
		trace = trace->next;
	}
	i++;
	return (i);
}


void	free_stack(t_list *head)
{
	t_list	*current;
	t_list	*liberation;

	if (head == NULL)
		return ;
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

void	free_or_no(char **argv, int c)
{
	int	y;

	y = 0;
	if (c == 1)
	{
		while (argv[y])
		{
			free(argv[y]);
			y++;
		}
		free(argv);
	}
}