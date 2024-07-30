/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:46:06 by acoste            #+#    #+#             */
/*   Updated: 2024/07/30 02:06:53 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	int				i;
	long long int	value_check;
	int				value;
	t_list			*node;
	t_list			*stack;

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
	check_doublon(&stack, value, argv, b);
	return (stack);
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
		return (list);
	}
}

int	main(int argc, char **argv)
{
	char	**list;
	int		b;

	b = 0;
	list = checkarg(argc, argv, &b);
	(void)list;
}