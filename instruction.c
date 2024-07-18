/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:47:57 by acoste            #+#    #+#             */
/*   Updated: 2024/07/18 20:28:05 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*temp;
	int		i;

	if (a == NULL || (*a)->next == (*a))
		return;
	temp = (*a)->before;
	i = (*a)->content;
	(*a)->content = temp->content;
	temp->content = i;
	write (1, "sa\n", 3);
	print_stack(*a); //a degager a la fin
}

void	sb(t_list **b)
{
	t_list	*temp;
	int		i;

	if (b == NULL || (*b)->next == (*b))
		return;
	temp = (*b)->before;
	i = (*b)->content;
	(*b)->content = temp->content;
	temp->content = i;
	write (1, "sb\n", 3);
	print_stack(*b); //a degager a la fin
}

// void	pb(t_list **a, t_list b)
// {
// 	if ()
// }

// pa

// pb
// 1ft
// ra

// rb

// rr
// 1ft
// rra

// rrb

// rrr