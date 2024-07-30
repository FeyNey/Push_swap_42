/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:47:57 by acoste            #+#    #+#             */
/*   Updated: 2024/07/30 15:16:07 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a)
{
	t_list	*big_node;

	big_node = find_max(*a);
	if (big_node == *a)
	{
		rotate_a(a);
	}
	else if ((*a)->next == big_node)
	{
		reverse_rotate_a(a);
	}
	if ((*a)->content > (*a)->next->content)
	{
		swap_a(a);
	}
}

/*
	Possible d'optimiser le code en comparant 1/2 et 2/3 entre eux avant
	de choisir la meuilleur option pour swap
*/

void	first_order_a(t_list **a, t_list **b)
{
	int	i;

	if (!(*a) || (*a)->next == (*a))
		return ;
	push_b(a, b);
	i = stack_lenght(*a);
	while (i > 3)
	{
		push_b(a, b);
		i--;
	}
	sort_three(a);
	give_index(a);
	give_index(b);
}

void	sort_algorithme(t_list **a)
{
	t_list	**b;
	t_list	*test;
	t_list	*node_min;
	t_list	*node_min2;

	test = NULL;
	b = &test;
	node_min = NULL;
	if (!(*a) || (*a)->next == (*a))
		return ;
	first_order_a(a, b);
	while ((*b) != (*a))
	{
		give_index(a);
		rotate_cost_a(a, 0, 1, stack_lenght(*a) / 2);
		rotate_cost_b(b);
		lowest_index(a, b, 0, 0);
		node_min = moove_cost(a, b, node_min);
		node_min2 = node_min;
		push_right_index(a, b, node_min, node_min2);
	}
	last_rotation(a);
	print_stack(*a);
}
	// //test
	// //test
	// printf(GREEN "---------- end of program -------\n" RESET);
	// printf("---------- stack *a -------\n");

	// if (stack_sorted(*a, stack_lenght(*a)) == 1)
	// {
	// 	printf(GREEN "\n\n\n          🎆🎆🎆🎆 SUCCES 🎆🎆🎆🎆 \n");
	// 	printf(GREEN "          🎆🎆🎆🎆 SUCCES 🎆🎆🎆🎆 \n");
	// 	printf(GREEN "          🎆🎆🎆🎆 SUCCES 🎆🎆🎆🎆 \n");
	// 	printf(GREEN "          🎆🎆🎆🎆 SUCCES 🎆🎆🎆🎆 \n");
	// 	printf(GREEN "          🎆🎆🎆🎆 SUCCES 🎆🎆🎆🎆 \n\n\n\n\n"RESET);
	// }