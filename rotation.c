/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:07:57 by acoste            #+#    #+#             */
/*   Updated: 2024/07/30 00:38:55 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	on_top_a(t_list **a, t_list *node_min, int i)
{
	int		nbr_rota;
	t_list	*temp;

	temp = (*a);
	while (temp->position != node_min->position)
	{
		temp = temp->next;
	}
	nbr_rota = temp->nbr_top_cost;
	if (above_median(a, temp) == 0)
	{
		while (i != nbr_rota)
		{
			rotate_a(a);
			i++;
		}
	}
	else
	{
		while (i != nbr_rota)
		{
			reverse_rotate_a(a);
			i++;
		}
	}
}

void	on_top_b(t_list **b, t_list *node_min)
{
	if (above_median(b, node_min) == 0)
	{
		while ((*b) != node_min)
		{
			rotate_b(b);
		}
	}
	else
	{
		while ((*b) != node_min)
		{
			reverse_rotate_b(b);
		}
	}
}

// void	on_top_both(t_list **a, t_list **b, t_list *node_min)
// {
// 	t_list *temp;

// 	temp = (*a);
// 	while (temp->position != node_min->position)
// 	{
// 		temp = temp->next;
// 	}
// 	if (above_median(a, temp) == 0 || above_median(b, node_min) == 0)
// 	{
// 		while (temp != (*a) && node_min != (*b))
// 		{
// 			rotate_ab(a, b);
// 		}
// 	}
// 	else if (above_median(a, temp) == 1 || above_median(b, node_min) == 1)
// 	{
// 		while (temp != (*a) && node_min != (*b))
// 		{
// 			reverse_rotate_ab(a, b);
// 		}
// 	}

// }

// void	on_top_both(t_list **a, t_list **b, t_list *node_min, t_list *nod)
// {
// 	t_list	*temp;
// 	int	i;
// 	int	nbr_rota;

// 	i = 0;
// 	temp = (*a);
// 	while (temp->position != node_min->position)
// 	{
// 		temp = temp->next;
// 	}
// 	nbr_rota = temp->nbr_top_cost;
	// if (above_median(a, temp) == 0 && above_median(b, node_min) == 0)
// 	{
// 		printf(MAGENTA "------------stack a-----------\n" RESET);
// 		print_stack(*a);
// 		printf(MAGENTA "------------stack b-----------\n" RESET);
// 		print_stack(*b);
// 		while (i != nbr_rota && node_min != (*b))
// 		{
// 			reverse_rotate_ab(a, b, node_min, nod);
// 			i++;
// 			printf(CYAN "------------stack a-----------\n" RESET);
// 			print_stack(*a);
// 			printf(CYAN "------------stack b-----------\n" RESET);
// 			print_stack(*b);
// 		}
// 	}
// 	else if (above_median(a, temp) == 1 && above_median(b, node_min) == 1)
// 	{
// 		printf(GREEN "------------stack a-----------\n" RESET);
// 		print_stack(*a);
// 		printf(GREEN "------------stack b-----------\n" RESET);
// 		print_stack(*b);
// 		while (i != nbr_rota || node_min != (*b))
// 		{
// 			rotate_ab(a, b, node_min, nod);
// 			i++;
// 			printf(RED "------------stack a-----------\n" RESET);
// 			print_stack(*a);
// 			printf(RED "------------stack b-----------\n" RESET);
// 			print_stack(*b);
// 		}
// 	}
// }

void	push_right_index(t_list **a, t_list **b, t_list *node_min, t_list *nod)
{
	on_top_a(a, node_min, 1);
	on_top_b(b, nod);
	push_a(a, b);
}
	// on_top_both(a, b, node_min);

void	last_rotation(t_list **a)
{
	t_list	*min;

	min = find_min(*a);
	while ((*a) != min)
	{
		if (above_median(a, min) == 0)
		{
			while ((*a) != min)
			{
				rotate_a(a);
			}
		}
		else
		{
			while ((*a) != min)
			{
				reverse_rotate_a(a);
			}
		}
	}
}
