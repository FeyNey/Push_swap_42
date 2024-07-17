/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:31:48 by acoste            #+#    #+#             */
/*   Updated: 2024/07/17 14:43:56 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *head)
{
	t_list *current;

	if (head == NULL)
		return;
	current = head;
	printf("%d\n", head->content);
	current = current->next;
	while (head != current && current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
}

//test function


int	stack_lenght(t_list *head)
{
	int	i;
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

void	check_doublon(t_list **head)
{
	t_list	*temp;
	int	y;
	int	len;

	y = 0;
	temp = (*head);
	len = stack_lenght(*head);
	temp = temp->next;
	while (y != len)
	{
		while (head && (*head) != temp)
		{
			if ((*head) == temp)
				ft_errors();
			temp = temp->next;
		}
		(*head) = (*head)->next;
		y++;
	}
}
