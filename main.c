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
	if (str)
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


// void	create_stack(char **argv)
// {

// }

int main(int argc, char **argv)
{
	char	**tab;
	char	*test;

	ft_checkargs(argc, argv[1]);
	if (argc == 2)
		tab = ft_split(argv[1], ' '); // problem
	else
		ft_checkargs2(argv);
	test = argv[1];
	ft_atoi(test);
//	ft_push_swap(tab);
}
