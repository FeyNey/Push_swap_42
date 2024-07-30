/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:47:57 by acoste            #+#    #+#             */
/*   Updated: 2024/07/30 00:44:17 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **a)
{
	t_list	*temp;
	int		i;

	if (a == NULL || (*a)->next == (*a))
		return ;
	temp = (*a)->next;
	i = (*a)->content;
	(*a)->content = temp->content;
	temp->content = i;
	write (1, "sa\n", 3);
}

void	swap_b(t_list **b)
{
	t_list	*temp;
	int		i;

	if (b == NULL || (*b)->next == (*b))
		return ;
	temp = (*b)->next;
	i = (*b)->content;
	(*b)->content = temp->content;
	temp->content = i;
	write(1, "sb\n", 3);
}
