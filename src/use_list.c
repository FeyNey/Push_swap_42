/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:31:48 by acoste            #+#    #+#             */
/*   Updated: 2024/07/18 11:20:16 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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