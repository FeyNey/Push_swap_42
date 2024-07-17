/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:31:48 by acoste            #+#    #+#             */
/*   Updated: 2024/07/17 22:09:35 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *head)
{
	t_list *current;

	if (head == NULL)
		return;
	current = head;
	printf("%d\n", head->content);
	current = current->next;
	while (head != current && current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
}

//test function

int	stack_lenght(t_list *head)
{
	int	i;
	t_list	*trace;

	if (head == NULL)
		return ('0');
	i = 0;
	trace = head;
	trace = trace->next;
	while (trace->next != NULL && trace != head)
	{
		i++;
		trace = trace->next;
	}
	i++;
	return (i);
}

// void	check_doublon(t_list **head)
// {
// 	t_list *temp;
// 	int	i;
// 	int	len;

// 	if ((*head) == NULL)
// 		return;
// 	i = 0;
// 	temp = (*head);
// 	temp = temp->next;
// 	len = stack_lenght((*head));
// 	while ((*head)->content != temp->content)
// 	{
// 		i++;
// 		temp = temp->next;
// 	}
// 	i++;
// 	if ((*head)->content == temp->content && i != len)
// 		ft_errors();
// }

void	check_doublon(t_list **head)
{
	t_list *temp;
	t_list *word;
	int	i;
	int	len;

	if ((*head) == NULL)
		return;
	i = 0;
	temp = (*head);
	temp = temp->next;
	word = (*head);
	len = stack_lenght((*head));
	// printf("%d = %d\n", );
	while (temp->content != (*head)->content)
	{
		while (word->content != temp->content)
		{
			i++;
			temp = temp->next;
		}
		i++;
		if (word->content == temp->content && i != len)
			ft_errors();
		i = 0;
		word = word->next;
		temp = word->next;
	}
	i++;
	if (word->content == temp->content && i != len)
			ft_errors();
	printf("a");
}
