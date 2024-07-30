/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:43:12 by acoste            #+#    #+#             */
/*   Updated: 2024/07/29 20:25:04 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_list *list)
{
	int		i;
	int		len;
	t_list	*temp;
	t_list	*max;

	if (!list || list->next == list)
		return (0);
	i = 0;
	max = list;
	len = stack_lenght(list);
	temp = list->next;
	while (i < len)
	{
		if (temp->content > max->content)
			max = temp;
		temp = temp->next;
		i++;
	}
	return (max);
}

t_list	*find_min(t_list *list)
{
	int		i;
	int		len;
	t_list	*temp;
	t_list	*min;

	if (!list || list->next == list)
		return (0);
	i = 0;
	min = list;
	len = stack_lenght(list);
	temp = list->next;
	while (i < len)
	{
		if (temp->content < min->content)
			min = temp;
		temp = temp->next;
		i++;
	}
	return (min);
}

void	rotate_cost_b(t_list **b)
{
	int		i;
	int		len;
	t_list	*temp;

	temp = (*b);
	i = 0;
	len = stack_lenght(*b) / 2;
	while (i <= len)
	{
		(*b)->nbr_top_cost = i;
		(*b) = (*b)->next;
		i++;
	}
	i--;
	if (stack_lenght(*b) % 2 == 0)
		i--;
	while (i > 0)
	{
		(*b)->nbr_top_cost = i;
		(*b) = (*b)->next;
		i--;
	}
	(*b) = temp;
}

	// i = 0;
	// len = stack_lenght(*b);
	// while (i < len)
	// {
	// 	printf(CYAN " ||  b pile ||\n" RESET);
	// 	printf("|||  node content = %d  |||\n", (*b)->content);
	// 	printf("|||  nbr_top_cost = %d   |||\n", (*b)->nbr_top_cost);
	// 	i++;
	// 	(*b) = (*b)->next;
	// }
	// (*b) = temp;

void	rotate_cost_a(t_list **a, int i, int nbr, int len)
{
	t_list	*head;

	head = (*a);
	while (i <= len)
	{
		(*a)->nbr_top_cost = nbr;
		(*a) = (*a)->next;
		i++;
		nbr++;
	}
	i--;
	nbr--;
	if (stack_lenght(*a) % 2 == 0)
	{
		nbr--;
		i--;
	}
	while (i > 0)
	{
		(*a)->nbr_top_cost = nbr;
		(*a) = (*a)->next;
		i--;
		nbr--;
	}
	(*a) = head;
}

// test
// 	*i = 0;
// 	int len = stack_lenght(*a);
// 	while ((*i) < len)
// 	{
// 		printf(MAGENTA " || a pile ||\n" RESET);
// 		printf("|||  node content = %d  |||\n", (*a)->content);
// 		printf("|||  nbr_top_cost = %d   |||\n", (*a)->nbr_top_cost);
// 		(*a) = (*a)->next;
// 		i++;
// 	}
// 	(*a) = head;