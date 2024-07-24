/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:47:57 by acoste            #+#    #+#             */
/*   Updated: 2024/07/25 01:12:11 by acoste           ###   ########.fr       */
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

	i = 0;
	y = 0;
	len_a = stack_lenght(*a);
	temp = (*b);
	len_b = stack_lenght(*b);
	while (y < len_b) // tant que je parcour ma chaine b
	{
		i = 0;
		min_max = find_max(*a)->content + 1;
		while (i < len_a) // tant que je parcours ma chaine a
		{
			if ((*a)->content > (*b)->content && (*a)->content < min_max)
			{
				(*b)->position = (*a)->position;
				min_max = (*a)->content;
			}
			i++;
			(*a) = (*a)->next;
		}
		if ((*b)->content < find_min(*a)->content)
			(*b)->position = 1;  //index du find max;
		if ((*b)->content > find_max(*a)->content)
			(*b)->position = 1;  // index du find min;
		temp = temp->next;
		(*b) = (*b)->next;
		y++;
	}
}
// 	*a = temp2->before;
// 	printf("\n--------------stack a------------\n\n");
// 	print_stack(*a);
// 	while (i < stack_lenght(*a))
// 	{
// 		printf("numero a-> %d\n", (*a)->content);
// 		printf("index sur a -> %d\n", (*a)->position);
// 		i++;
// 		(*a) = (*a)->next;
// 	}
// 	*b = temp3;
// 	printf("\n--------------stack b------------\n\n");
// 	print_stack(*b);
// 	printf("\n--------------------------\n\n");
// 	i = 0;
// 	len_b = stack_lenght(*b);
// 	while (i < len_b)
// 	{
// 		printf("numero b-> %d\n", (*b)->content);
// 		printf("index sur b -> %d\n\n", (*b)->position);
// 		i++;
// 		(*b) = (*b)->next;
// 	}

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

t_list	*moove_cost(t_list **a, t_list **b, t_list *node_min)
{
	int i;
	int	min_cost_moove;

	i = 0;
	node_min = (*a);
	min_cost_moove = 2147483647;
	while (i < stack_lenght(*b))
	{
		while ((*b)->position != (*a)->position) //optimisation du sens de rota possible
			(*a) = (*a)->next;
		if (min_cost_moove > (*a)->nbr_top_cost + (*b)->nbr_top_cost)
		{
			min_cost_moove = (*a)->nbr_top_cost + (*b)->nbr_top_cost;
			node_min = (*b);
		}
		(*b) = (*b)->next;
		i++;
	}
	printf ("\n----------------------\n");
	printf ("node min = %d", node_min->content);
	printf ("\n----------------------\n");
	return (node_min);
}

int	above_median(t_list **pile, t_list *node)
{
	int	i;
	int	len;
	t_list	*head;

	len = stack_lenght(*pile);
	if (len % 2 == 1)
		len = len + 1;
	i = 0;
	head = (*pile);
	len = stack_lenght(*pile);
	while (*pile != node)
	{
		*pile = ((*pile)->next);
		i++;
	}
	*pile = head;
	if (i <= len / 2)
		return (0);
	else
		return (1);
	*pile = head;
}

void	on_top_a(t_list **a, t_list *node_min, int len_a)
{
	int	i;
	// t_list	**head;

	i = 0;
	// head = a;
	while (i < len_a)
	{
		if ((node_min->position < len_a / 2) && (node_min != (*a)))
		{
			rotate_a(a);
			node_min = node_min->next;
		}
		else if (node_min != (*a))
		{
			reverse_rotate_a(a);
			node_min = node_min->before;
		}
		i++;
	}
	print_stack(*a);
}

void	on_top_b(t_list **b, t_list *node_min, int len_b)
{
	t_list	*head;

	(void)len_b;
	head = (*b);
	if (above_median(b, node_min) == 1)
	{
		while((*b) != node_min)
		{
			rotate_b(b);
			node_min = node_min->next;
		}
	}
	else
	{
		while ((*b) != node_min)
		{
			reverse_rotate_b(b);
			node_min = node_min->before;
		}
	}
	(*b) = head;
	print_stack(*b);
}

void	push_right_index(t_list **a, t_list **b, t_list *node_min, t_list *nod)
{
	int	len_a;
	int	len_b;

	len_a = stack_lenght(*a);
	len_b = stack_lenght(*b);
	printf("\n\n--------------After algo------------\n\n");
	on_top_a(a, node_min, len_a);
	on_top_b(b, nod, len_b);
	push_a(a, b);
}

void	sort_algorithme(t_list **a)
{
	t_list **b;
	t_list *test;
	t_list *node_min;
	t_list *node_min2;

	test = NULL;
	b = &test;
	node_min = NULL;
	if (!(*a) || (*a)->next == (*a))
		return;
	first_order_a(a, b);
	print_stack(*a);
	print_stack(*b);
	rotate_cost_a(a);
	rotate_cost_b(b);
	lowest_index(a, b);
	node_min = moove_cost(a, b, node_min);
	node_min2 = node_min;
	printf("ok\n");
	push_right_index(a, b, node_min, node_min2);
}