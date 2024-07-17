/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:16:01 by acoste            #+#    #+#             */
/*   Updated: 2024/07/08 18:16:01 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h> // pas autorise printf test
# include <stdlib.h>

typedef struct s_list {

	int				content;
	struct s_list	*next;
	struct s_list	*before;

} t_list;

char	**ft_split(char *s, char c);
void	ft_checkargs(int n, char *argv);
void	ft_checkargs2(char** argv);
void	ft_errors(void);
t_list	*ft_lstnew(int content);
void	ft_lstadd_end(t_list **head, t_list *node);
void	ft_lstadd_start(t_list **head, t_list *node);
void	free_stack(t_list *head);
void	print_stack(t_list *head);
int	stack_lenght(t_list *head);
void	check_doublon(t_list **head);
char	**checkarg(int argc, char **argv);
void	freesplit(char **tab);

#endif
