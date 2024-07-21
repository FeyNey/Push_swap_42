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

t_list	*create_stack(char **argv, int *b)
{
	int	i;
	int	value;
	t_list	*node;
	t_list	*stack;

	stack = NULL;
	i = 0;
	while (argv[i])
	{
		value = ft_atoi(argv[i], b);
		node = ft_lstnew(value);
		ft_lstadd_end(&stack, node);
		i++;
	}
	// print_stack(stack);
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
	printf ("stack before algo\n");
	print_stack(a);
	if (stack_sorted(a, len) == 1)
	{
		if (len == 2)
			swap_a(&a);
		else if (len == 3)
			sort_three(&a);
		else
		{
			sort_algorithme(&a);
		}
	}
	free_or_no(list, *p);
	free_stack(a);
	printf("freed stacks\n");
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
