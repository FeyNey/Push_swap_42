/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_attribute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:06:29 by acoste            #+#    #+#             */
/*   Updated: 2024/07/29 21:07:24 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lowest_index(t_list **a, t_list **b, int i, int y)
{
	int		len_a;
	int		len_b;
	int		min_max;
	t_list	*temp;

	len_a = stack_lenght(*a);
	temp = (*b);
	len_b = stack_lenght(*b);
	while (y < len_b)
	{
		i = 0;
		min_max = find_max(*a)->content + 1;
		while (i < len_a)
		{
			if ((*a)->content > (*b)->content && (*a)->content < min_max)
			{
				(*b)->position = (*a)->position;
				min_max = (*a)->content;
			}
			i++;
			(*a) = (*a)->next;
		}
		lowest_index_min_max(a, b, temp);
		y++;
	}
}
// void	lowest_index_search(t_list **a, t_list **b)
// {
// 	int		i;
// 	int		y;
// 	int		len_a;
// 	int		len_b;
// 	int		min_max;

// 	i = 0;
// 	y = 0;
// 	len_a = stack_lenght(*a);
// 	len_b = stack_lenght(*b);
// 	while (y < len_b)
// 	{
// 		i = 0;
// 		min_max = find_max(*a)->content + 1;
// 		while (i < len_a)
// 		{
// 			if (lowest_index(a, b, min_max) == 1)
// 				min_max = (*a)->content;
// 			i++;
// 		}
// 		lowest_index_min_max(a, b);
// 		(*b) = (*b)->next;
// 		y++;
// 	}
// }

// int	lowest_index(t_list **a, t_list **b, int min_max)
// {
// 	int	i;

// 	i = 0;
// 	if ((*a)->content > (*b)->content && (*a)->content < min_max)
// 	{
// 		(*b)->position = (*a)->position;
// 		min_max = (*a)->content;
// 		i = 1;
// 	}
// 	(*a) = (*a)->next;
// 	if (i == 0)
// 		return (0);
// 	else
// 		return (1);
// }

void	lowest_index_min_max(t_list **a, t_list **b, t_list *temp)
{
	if ((*b)->content < find_min(*a)->content)
		(*b)->position = find_min(*a)->position;
	if ((*b)->content > find_max(*a)->content)
		(*b)->position = find_min(*a)->position;
	temp = temp->next;
	(*b) = (*b)->next;
}
	// t_list *temp = (*a);
	// t_list *temp2 = (*b);
	// while (i < stack_lenght(*a))
	// {
	// 	printf("a content -> %d\n", (*a)->content);
	// 	printf("a position -> %d\n", (*a)->position);
	// 	i++;
	// 	(*a) = (*a)->next;
	// }
	// printf("\n--------------stack b------------\n\n");
	// print_stack(*b);
	// printf("\n--------------------------\n\n");
	// i = 0;
	// int len_b = 0;
	// len_b = stack_lenght(*b);
	// while (i < len_b)
	// {
	// 	printf("numero b-> %d\n", (*b)->content);
	// 	printf("index sur b -> %d\n\n", (*b)->position);
	// 	i++;
	// 	(*b) = (*b)->next;
	// }
	// (*a) = temp;
	// (*b) = temp2;
	// printf("\n--------------stack a------------\n\n");
	// print_stack(*a);