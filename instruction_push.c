/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:44:39 by acoste            #+#    #+#             */
/*   Updated: 2024/07/30 00:44:27 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialised_b(t_list **a, t_list **b)
{
	t_list	*tail_a;
	t_list	*second_a;

	tail_a = (*a)->before;
	second_a = (*a)->next;
	tail_a->next = second_a;
	second_a->before = tail_a;
	(*b)->next = *b;
	(*b)->before = *b;
	(*a) = second_a;
	write(1, "pb\n", 3);
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tail_a;
	t_list	*tail_b;
	t_list	*second_a;

	if (!a && !b)
		return ;
	if ((*b) == NULL)
	{
		(*b) = (*a);
		initialised_b(a, b);
	}
	else
	{
		tail_a = (*a)->before;
		tail_b = (*b)->before;
		second_a = (*a)->next;
		push_b_complete(a, b, tail_b);
		second_a->before = tail_a;
		tail_a->next = second_a;
		(*a) = second_a;
		(*b) = (*b)->before;
		write(1, "pb\n", 3);
	}
}

void	push_b_complete(t_list **a, t_list **b, t_list *tail_b)
{
	(*a)->next = (*b);
	(*a)->before = tail_b;
	(*b)->before = (*a);
	tail_b->next = (*a);
}

int	push_a(t_list **a, t_list **b)
{
	t_list	*tail_a;
	t_list	*tail_b;
	t_list	*second_b;

	if (stack_lenght(*b) == 1)
	{
		last_stack_element(a, b);
		return (1);
	}
	if (!a)
		return (1);
	tail_a = (*a)->before;
	tail_b = (*b)->before;
	second_b = (*b)->next;
	tail_b->next = second_b;
	second_b->before = tail_b;
	(*b)->before = tail_a;
	(*b)->next = (*a);
	(*a)->before = (*b);
	tail_a->next = (*b);
	(*b) = second_b;
	(*a) = (*a)->before;
	write(1, "pa\n", 3);
	return (0);
}
