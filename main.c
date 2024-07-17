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
		res = res*10;
		res = res + str[i] - '0';
		i++;
	}
	if (res > intmax || res < -intmax)
	{
		write(1, "Error\n", 7);
		exit(EXIT_FAILURE);
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

int	checkarg(int argc, char **argv)
{
	ft_checkargs(argc, argv[1]);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		return (1);
	}
	else
	{
		ft_checkargs2(argv);
		return(2);
	}
}

int main(int argc, char **argv)
{
	int	i;
	int	c;
	// t_list *a;
	// t_list *b;

	// a = NULL;
	// b = NULL;
	i = 0;
	c = checkarg(argc, argv);	//{
	argv = &argv[1];			// a tester//}
	create_stack(argv);
	//if b == 2
	//	freemonsplit

//	ft_push_swap(tab);
}
