/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:47:57 by acoste            #+#    #+#             */
/*   Updated: 2024/07/20 17:10:53 by acoste           ###   ########.fr       */
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
		print_stack(*a);
	}
	else if ((*a)->next == big_node)
	{
		reverse_rotate_a(a);
		print_stack(*a);
	}
	if ((*a)->content > (*a)->next->content)
	{
		swap_a(a);
		print_stack(*a);
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
	printf("max = %d\n", max->content); // a degager
	return (max);
}

void	give_index(t_list **a)
{
	int	i;
	int	len;

	i = 0;
	len = stack_lenght(*a);
	while (i < len)
	{
		(*a)->position = i;
		i++;
	}
}

void	first_order_a(t_list **a, t_list **b)
{
	int	i;

	i = stack_lenght;
	if (!(*a) || (*a)->next == (*a))
		return(0);
	while (i > 2)
	{
		push_b(a, b);
		i--;
	}
	sort_three(a);
	give_index(a);
}

void	give_index(t_list **list)
{
	int	i;
	t_list	*temp;

	i = 1;
	temp = (*list)->next;
	list->position = i;
	while ((*list)->content != (*temp)->content)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}

void	lowest_biggest_number(t_list **b)
{
	/*
		attribuer a la pile b le nombre le plus proche devant lequel ils doivent
		s'inserer
	*/
}

void	lowest_index(t_list **b)
{
	if (!b)
		return (0)
/*
	mettre en index a la pile b le nombre de coup necessaire pour etre bouger
*/
}


void	sort_algorithme(t_list **a, t_list **b)
{
	if (!(*a) || !(*a)->next)
		return(0);
	first_order_a(a, b);
	give_index(b);
	if (!(*b))
	{
		printf("Error B implementation");	//supp apres test
		exit;								//supp apres test
	}
	lowest_index(b);

	while ()
	{

	}

}


