/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:03:07 by acoste            #+#    #+#             */
/*   Updated: 2024/07/30 02:03:17 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checkargs2(char **argv)
{
	int	i;
	int	y;

	y = 1;
	while (argv[y])
	{
		i = 0;
		while (argv[y][i])
		{
			if ((argv[y][i] >= 0 && argv[y][i] <= 6) ||
				(argv[y][i] >= 14 && argv[y][i] <= 32) ||
				(argv[y][i] >= 33 && argv[y][i] <= 42) ||
				(argv[y][i] >= 46 && argv[y][i] <= 47) ||
				(argv[y][i] >= 58) ||
				(argv[y][i] == 44) ||
				((argv[y][i] == '-' || argv[y][i] == '+') &&
				(argv[y][i + 1] <= 47 || argv[y][i + 1] >= 58)) ||
				((argv[y][i] == '-' || argv[y][i] == '+') &&
				(argv[y][i - 1] >= 47 && argv[y][i - 1] <= 58)))
				ft_errors();
			i++;
		}
		y++;
	}
}

void	ft_checkargs(int n, char *argv)
{
	int	i;

	i = 0;
	if (n == 1)
		exit(EXIT_FAILURE);
	if (n == 2)
	{
		while (argv[i])
		{
			if ((argv[i] >= 0 && argv[i] <= 6)
				|| (argv[i] >= 14 && argv[i] <= 31)
				|| (argv[i] >= 33 && argv[i] <= 42)
				|| (argv[i] >= 46 && argv[i] <= 47)
				|| (argv[i] >= 58)
				|| (argv[i] == 44)
				|| ((argv[i] == '-' || argv[i] == '+')
					&& (argv[i + 1] <= 47 || argv[i + 1] >= 58))
				|| ((argv[i] == '-' || argv[i] == '+')
					&& (argv[i - 1] >= 47 && argv[i - 1] <= 58)))
				ft_errors();
			i++;
		}
	}
}

void	check_doublon(t_list **head, int len, char **argv, int *b)
{
	t_list	*temp;
	t_list	*word;
	int		i;

	i = 0;
	temp = (*head)->next;
	word = (*head);
	while (temp->content != (*head)->content)
	{
		while (word->content != temp->content)
		{
			i++;
			temp = temp->next;
		}
		i++;
		if (word->content == temp->content && i != len)
			check_doublon_error(head, argv, b);
		i = 0;
		word = word->next;
		temp = word->next;
	}
	i++;
	if (word->content == temp->content && i != len)
		check_doublon_error(head, argv, b);
}

void	ft_errors(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_doublon_error(t_list **head, char **argv, int *b)
{
	free_or_no(argv, *b);
	free_stack(*head);
	ft_errors();
}
