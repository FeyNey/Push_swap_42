/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:31:48 by acoste            #+#    #+#             */
/*   Updated: 2024/07/16 12:54:33 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *head)
{
	t_list *current;

	if (head == NULL)
		printf ("Stack is empty\n"); // test
	return;
	current = head;
	printf("%d\n", head->content);
	head = head->next;
	while (current != head)
	{
		printf("%d\n", head->content);
		head = head->next;
	}
	printf("full stack printed\n");
}

//test function
