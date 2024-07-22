/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:47:57 by acoste            #+#    #+#             */
/*   Updated: 2024/07/22 22:57:15 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_list *a, int len)
{
	t_list *temp;
	int	i;

	i = 0;
	if (!a)
		return(1);
	temp = a->next;
	while (temp->content != a->content && i != len)
	{
		while (temp->content != a->content)
		{
			i = 0;
			if (a->content > temp->content)
				return(1);
			temp = temp->next;
			i++;
		}
		a = a->next;
		temp = a->next;
		i++;
	}
	return(0);
}

void	sort_three(t_list **a)
{
	t_list *big_node;

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
	print_stack(*a);
}

/*
	Possible d'optimiser le code en comparant 1/2 et 2/3 entre eux avant
	de choisir la meuilleur option pour swap
*/

t_list	*find_max(t_list *list)
{
	int i;
	int len;
	t_list *temp;
	t_list *max;

	if (!list || list->next == list)
		return(0);
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
	printf("max = %d\n", max->content); // a degager
	return (max);
}

void	give_index(t_list **list)
{
	int	i;
	int	len;
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

void	first_order_a(t_list **a, t_list **b)
{
	int	i;

	if (!(*a) || (*a)->next == (*a))
		return;
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


// void	lowest_biggest_number(t_list **b)
// {
// 	/*
// 		attribuer a la pile b le nombre le plus proche devant lequel ils doivent
// 		s'inserer
// 	*/
// }

t_list	*find_min(t_list *list)
{
	int i;
	int len;
	t_list *temp;
	t_list *min;

	if (!list || list->next == list)
		return(0);
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
	printf("min = %d\n", min->content); // a degager
	return (min);
}

void	lowest_index(t_list **a, t_list **b)
{
	int	i;
	int	y;
	int	len_a;
	int	len_b;
	int	min_max;
	t_list *temp;
	t_list *temp2;
	t_list *temp3;

	(void)min_max;
	temp2 = (*a);
	temp3 = (*b);
	printf("\n--------------------------\n\n");
	i = 0;
	y = 0;
	len_a = stack_lenght(*a);
	temp = (*b);
	len_b = stack_lenght(*b);
	while (y < len_b) // tant que je parcour ma chaine b
	{
		i = 0;
		min_max = 2147483647;
		while (i < len_a) // tant que je parcours ma chaine a
		{
			if ((*a)->content > (*b)->content) //&& (*a)->content < min_max
			{
				(*b)->position = (*a)->position;
				min_max = (*a)->content;
			}
			i++;
			(*a) = (*a)->next;
		}
		if ((*b)->content < find_min(*a)->content)
			(*b)->position = 1;
		if ((*b)->content > find_max(*a)->content)
			(*b)->position = 1;
		temp = temp->next;
		y++;
	}
	i = 0;
	*a = temp2->before;
	printf("\n--------------stack a------------\n\n");
	print_stack(*a);
	while (i < stack_lenght(*a))
	{
		printf("numero a-> %d\n", (*a)->content);
		printf("index sur a -> %d\n", (*a)->position);
		i++;
		(*a) = (*a)->next;
	}
	*b = temp3;
	printf("\n--------------stack b------------\n\n");
	print_stack(*b);
	printf("\n--------------------------\n\n");
	i = 0;
	len_b = stack_lenght(*b);
	while (i < len_b)
	{
		printf("numero b-> %d\n", (*b)->content);
		printf("index sur b -> %d\n", (*b)->position);
		i++;
		(*b) = (*b)->next;
	}
}

		// s occuper du min et du max
/*
	mettre en index a la pile b le nombre de coup necessaire pour etre bouger
*/
void	rotate_cost_a(t_list **a)
{
	int		i;
	int		len;

	i = 0;
	len = stack_lenght(*a) / 2;
	while (i <= len + 1) //verif
	{
		(*a)->nbr_top_cost = i;
		(*a) = (*a)->next;
		i++;
	}
	if (stack_lenght(*a) % 2 == 1)
		i++;
	while (i > 0)
	{
		(*a)->nbr_top_cost = i;
		(*a) = (*a)->next;
		i--;
	}
}

void	rotate_cost_b(t_list **b)
{
	int	i;
	int	len;
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
	i = 0;
	(*b) = temp;
	len = len * 2;
}

void	sort_algorithme(t_list **a)
{
	t_list **b;
	t_list *test;

	test = NULL;
	b = &test;
	if (!(*a) || (*a)->next == (*a))
		return;
	first_order_a(a, b);
	printf("objectif\n");
	rotate_cost_a(a);
	rotate_cost_b(b);
	lowest_index(a, b); // continuer
}
// 	while ()
// 	{

// 	}

// }
