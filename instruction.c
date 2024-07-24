/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:47:57 by acoste            #+#    #+#             */
/*   Updated: 2024/07/24 18:04:49 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	swap_a(t_list **a)
{
	t_list	*temp;
	int		i;

	if (a == NULL || (*a)->next == (*a))
		return;
	temp = (*a)->next;
	i = (*a)->content;
	(*a)->content = temp->content;
	temp->content = i;
	write (1, "sa\n", 3);
	print_stack(*a); //a degager a la fin
}

void	swap_b(t_list **b)
{
	t_list	*temp;
	int		i;

	if (b == NULL || (*b)->next == (*b))
		return;
	temp = (*b)->next;
	i = (*b)->content;
	(*b)->content = temp->content;
	temp->content = i;
	write(1, "sb\n", 3);
	print_stack(*b); //a degager a la fin
}

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

void	last_stack_element(t_list **a, t_list **b)
{
	t_list	*tail_a;

	tail_a = (*a)->before;
	(*b)->before = tail_a;
	(*b)->next = (*a);
	(*a)->before = (*b);
	tail_a->next = (*b);
	(*a) = (*a)->before;
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
// if stack a taille < 2 segfault a gerer


void	push_b(t_list **a, t_list **b)
{
	t_list	*tail_a;
	t_list	*tail_b;
	t_list	*second_a;

	if (!a && !b)
		return;
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
		(*a)->next = (*b);
		(*a)->before = tail_b;
		(*b)->before = (*a);
		tail_b->next = (*a);
		second_a->before = tail_a;
		tail_a->next = second_a;
		(*a) = second_a;
		(*b) = (*b)->before;
		write(1, "pb\n", 3);
	}
}

// if stack taille < 2 segfault a gerer;

void	rotate_a(t_list **a)
{
	if (!*a || !(*a)->next)
		return;
	(*a) = (*a)->next;
	write(1, "ra\n", 3);
}