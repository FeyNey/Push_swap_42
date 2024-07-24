/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:49:36 by acoste            #+#    #+#             */
/*   Updated: 2024/07/24 21:51:41 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_list **b)
{
	if (!*b || !(*b)->next)
		return;
	(*b) = (*b)->next;
	write(1, "rb\n", 3);
}

void	rotate_ab(t_list **a, t_list **b)
{
	if (!(*a) || !(*a)->next || !(*b) || (*b)->next)
		return;
	(*a) = (*a)->next;
	(*b) = (*b)->next;
	write(1, "rr\n", 3);
}

// rra
void	reverse_rotate_a(t_list **a)
{
	if (!(*a) || !(*a)->next)
		return ;
	(*a) = (*a)->before;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **b)
{
	if (!(*b))
		return;
	(*b) = (*b)->before;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_list **a, t_list **b)
{
	if (!(*a) || !(*a)->next || !(*b) || (*b)->next)
		return;
	(*a) = (*a)->before;
	(*b) = (*b)->before;
	write(1, "rrr\n", 4);
}