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

int	ft_atoi(char *str)
{
	int i;
	int sign;
	long long int res;
	int	intmax;

	i = 0;
	sign = 1;
	res = 0;
	intmax = 2147483647;
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
	if (res > intmax || res < -intmax)
	{
		write(1, "Error\n", 7);
		exit(EXIT_FAILURE);		//traiter le free du split
	}
	return (res * sign);
}


void	create_stack(char **argv)
{
	int	i;
	int	value;
	t_list	*node;
	t_list	*stack;

	stack = NULL;
	i = 0;

	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		node = ft_lstnew(value);
		ft_lstadd_end(&stack, node);
		i++;
	}
	print_stack(stack);
	stack_lenght(stack);
	check_doublon(&stack);
	free_stack(stack);
}

char	**checkarg(int argc, char **argv)
{
	char	**list;
	ft_checkargs(argc, argv[1]);
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
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
	int	i;
	char	**list;
	// t_list *a;
	// t_list *b;

	// a = NULL;
	// b = NULL;
	i = 0;
	list = checkarg(argc, argv);
	// check_doublon(argv); *************************
	create_stack(list);

//	ft_push_swap(tab);
}
