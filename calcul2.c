/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:58:19 by acoste            #+#    #+#             */
/*   Updated: 2024/07/30 00:40:07 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_list *a, int len)
{
	t_list	*temp;
	int		y;
	int		i;

	y = 1;
	if (!a)
		return (1);
	temp = a->next;
	while (temp->content != a->content && y != len)
	{
		i = y;
		while (temp->content != a->content && i != len)
		{
			if (a->content > temp->content)
				return (1);
			temp = temp->next;
			i++;
		}
		a = a->next;
		temp = a->next;
		y++;
	}
	return (0);
}

void	give_index(t_list **list)
{
	int		i;
	int		len;
	t_list	*temp;

	i = 1;
	len = stack_lenght(*list);
	temp = (*list)->next;
	(*list)->position = i;
	i++;
	while (i < len + 1)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}
// 	// test
// 	i = 0;
// 	len = stack_lenght(*list);
// 	while (i < len)
// 	{
// 		i++;
// 		(*list) = (*list)->next;
// 	}

int	above_median(t_list **pile, t_list *node)
{
	int		i;
	int		len;
	t_list	*head;

	head = (*pile);
	len = stack_lenght(*pile);
	i = 0;
	while (*pile != node)
	{
		*pile = ((*pile)->next);
		i++;
	}
	*pile = head;
	if (i <= (len / 2))
		return (0);
	else
		return (1);
}

t_list	*moove_cost(t_list **a, t_list **b, t_list *node_min)
{
	int		i;
	int		min_cost_moove;
	t_list	*head;

	head = (*a);
	i = 0;
	node_min = (*a);
	min_cost_moove = 2147483647;
	while (i < stack_lenght(*b))
	{
		while ((*b)->position != (*a)->position)
			(*a) = (*a)->next;
		if (min_cost_moove > (*a)->nbr_top_cost + (*b)->nbr_top_cost)
		{
			min_cost_moove = (*a)->nbr_top_cost + (*b)->nbr_top_cost;
			node_min = (*b);
		}
		(*b) = (*b)->next;
		i++;
	}
	(*a) = head;
	return (node_min);
}
	//test
	// printf ("\n----------------------\n");
	// printf ("node min = %d", node_min->content);
	// printf ("\n----------------------\n");
	//test
		// printf("||| b content : %d  |||", (*b)->content);
		// printf(" b position : %d |||\n", (*b)->position);
		// printf("||| a content : %d |||", (*a)->content);
		// printf("||| a position : %d |||\n", (*a)->position);