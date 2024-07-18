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

void	create_stack(char **argv, int *b)
{
	int	i;
	int	value;
	t_list	*node;
	t_list	*stack;

	stack = NULL;
	i = 0;
	while (argv[i])
	{
		value = ft_atoi(&argv[i], b);
		node = ft_lstnew(value);
		ft_lstadd_end(&stack, node);
		i++;
	}
	print_stack(stack);
	value = stack_lenght(stack);
	check_doublon(&stack, value);
	free_or_no(argv, *b);
	free_stack(stack);// ***********
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

int main(int argc, char **argv)
{
	char	**list;
	int		b;
	// int		i;
	// t_list *a;
	// t_list *c;

	b = 0;
	// i = 0;
	// a = NULL;
	// c = NULL;
	list = checkarg(argc, argv, &b);
	create_stack(list, &b);
//	ft_push_swap(tab);
}
