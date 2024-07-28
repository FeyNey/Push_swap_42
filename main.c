/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:15:28 by acoste            #+#    #+#             */
/*   Updated: 2024/07/08 18:15:28 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_value(long long int value, char **argv, int *b, t_list *stack)
{
	if ((value > 2147483647) || (value < -2147483648))
	{
		free_or_no(argv, *b);
		free_stack(stack);
		ft_errors();
	}
	return ((int)value);
}

t_list	*create_stack(char **argv, int *b)
{
	int	i;
	long long int	value_check;
	int value;
	t_list	*node;
	t_list	*stack;

	stack = NULL;
	i = 0;
	while (argv[i])
	{
		value_check = ft_atoi(argv[i]);
		value = check_value(value_check, &argv[0], b, stack);
		node = ft_lstnew(value);
		ft_lstadd_end(&stack, node);
		i++;
	}
	value = stack_lenght(stack);
	check_doublon(&stack, value);
	return(stack);
}

char	**checkarg(int argc, char **argv, int *b)
{
	char	**list;

	ft_checkargs(argc, argv[1]);
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		*b = 1;
		return (list);
	}
	else
	{
		ft_checkargs2(argv);
		list = argv;
		list = &list[1];
		return(list);
	}
}

void	algo_turc(char **list, int *p)
{
	t_list	*a;
	int	len;

	a = create_stack(list, p);
	len = stack_lenght(a);
	//test
	// printf(RED "stack before algo\n" RESET);
	// print_stack(a);
	//test
	if (stack_sorted(a, len) == 1)
	{
		if (len == 2)
			swap_a(&a);
		else if (len == 3)
			sort_three(&a);
		else
			sort_algorithme(&a);
	}
	free_or_no(list, *p);
	free_stack(a);
	//test
	// printf("freed stacks\n");
}

int main(int argc, char **argv)
{
	char	**list;
	int		b;

	b = 0;
	list = checkarg(argc, argv, &b);
	algo_turc(list, &b);
//	ft_push_swap(tab);
}
