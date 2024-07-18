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

// split
char	**ft_split(char *s, char c);
void	tab_split(char **tab, char *s, char c, int lastw);
void	freesplit(char **tab);
void	write_words(char *tab, char*s, char c);
int		count_words(char *s, char c);

// check erreurs
void	ft_checkargs(int n, char *argv);
void	ft_checkargs2(char** argv);
void	ft_errors(void);
void	check_doublon(t_list **head, int len);
char	**checkarg(int argc, char **argv, int *b);

//implementation pile / stack
t_list	*create_stack(char **argv, int *b);
t_list	*ft_lstnew(int content);
void	ft_lstadd_end(t_list **head, t_list *node);
void	ft_lstadd_start(t_list **head, t_list *node);
void	free_stack(t_list *head);
void	print_stack(t_list *head);
int		stack_lenght(t_list *head);
void	free_or_no(char **argv, int c);

//conversion
int	ft_atoi(char *str, int *b);

//algorithme
int	stack_sorted(t_list *a, int len);
void	algo_turc(char **list, int *p);
void	sort_three(t_list **a);

//tri
void	sa(t_list **a);

#endif
