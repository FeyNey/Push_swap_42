/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:47:57 by acoste            #+#    #+#             */
/*   Updated: 2024/07/18 20:11:56 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// int	stack_sorted(t_list *a, int len)
// {
// 	t_list *temp;
// 	int	i;

// 	i = 0;
// 	if (!a)
// 		return(1);
// 	temp = a->next;
// 	while (temp->content != a->content && i != len)
// 	{
// 		while (temp->content != a->content)
// 		{
// 			if (a->content > temp->content)
// 				return(1);
// 			temp = temp->next;
// 			i++;
// 		}
// 		a = a->next;
// 		temp = a->next;
// 		i++;
// 	}
// 	return(0);
// }

// void	sort_three(t_list **a)
// {
// 	t_list *big_node;

// 	big_node = find_max(*a);
// 	if (biggest_node == *a)
// 		// ra(a);
// 	else if ((*a)->next == big_node)
// 		//rra(a);
// 	if ((*a)->nbr > (*a)->next->content)
// 		// sa(a);
// }