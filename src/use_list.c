/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:31:48 by acoste            #+#    #+#             */
/*   Updated: 2024/07/28 18:15:46 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	print_stack(t_list *head)
// {
// 	t_list *current;
// 	printf("///////////////////////\n");
// 	if (head == NULL)
// 		return;
// 	current = head;
// 	printf("%d\n", head->content);
// 	current = current->next;
// 	while (head != current && current != NULL)
// 	{
// 		printf("%d\n", current->content);
// 		current = current->next;
// 	}
// 	printf("///////////////////////\n");
// }

//test function

int	stack_lenght(t_list *head)
{
	int		i;
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

long long int	ft_atoi(char *str)
{
	int				i;
	int				sign;
	long long int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[0] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	return (res * sign);
}
