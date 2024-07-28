/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:47:47 by acoste            #+#    #+#             */
/*   Updated: 2024/07/28 18:51:58 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_list **a)
{
	if (!*a || !(*a)->next)
		return ;
	(*a) = (*a)->next;
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **b)
{
	if (!*b || !(*b)->next)
		return ;
	(*b) = (*b)->next;
	write(1, "rb\n", 3);
}

void	rotate_ab(t_list **a, t_list **b)
{
	if (!(*a) || !(*a)->next || !(*b) || (*b)->next)
		return ;
	(*a) = (*a)->next;
	(*b) = (*b)->next;
	write(1, "rr\n", 3);
}
