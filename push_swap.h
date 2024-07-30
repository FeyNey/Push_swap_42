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
# include <stdlib.h>
# include <stdio.h> // pas autorise printf test

//test
// # define RED     "\x1b[31m" // test printf
// # define GREEN   "\x1b[32m"
// # define CYAN    "\x1b[36m"
// # define MAGENTA "\x1b[35m"
// # define YELLOW  "\x1b[33m"
// # define RESET   "\x1b[0m"

typedef struct s_list
{
	int				content;
	int				position;
	int				nbr_top_cost;
	struct s_list	*next;
	struct s_list	*before;

}	t_list;

//conversion
long long int	ft_atoi(char *str);

// split
char			**ft_split(char *s, char c);
void			tab_split(char **tab, char *s, char c, int lastw);
void			freesplit(char **tab);
void			write_words(char *tab, char*s, char c);
int				count_words(char *s, char c);

// check erreurs
void			ft_checkargs(int n, char *argv);
void			ft_checkargs2(char **argv);
void			ft_errors(void);
void			check_doublon(t_list **head, int len, char **argv, int *b);
void			check_doublon_error(t_list **head, char **argv, int *b);
char			**checkarg(int argc, char **argv, int *b);

//implementation pile / stack
int				stack_lenght(t_list *head);
t_list			*create_stack(char **argv, int *b);
t_list			*ft_lstnew(int content);
void			ft_lstadd_end(t_list **head, t_list *node);
void			ft_lstadd_start(t_list **head, t_list *node);
void			free_stack(t_list *head);
int				stack_lenght(t_list *head);
void			free_or_no(char **argv, int c);
void			print_stack(t_list *head);

//conversion
int				check_value(long long int value, char **argv,
					int *b, t_list *stack);

//algorithme
int				stack_sorted(t_list *a, int len);
void			algo_turc(char **list, int *p);
void			sort_three(t_list **a);
void			sort_algorithme(t_list **a);
//modif
void			lowest_index_search(t_list **a, t_list **b);
void			lowest_index(t_list **a, t_list **b, int i, int y);
void			lowest_index_min_max(t_list **a, t_list **b, t_list *temp);
void			first_order_a(t_list **a, t_list **b);
void			on_top_a(t_list **a, t_list *node_min, int i);
void			on_top_b(t_list **b, t_list *node_min);
void			push_right_index(t_list **a, t_list **b,
					t_list *node_min, t_list *nod);
void			last_rotation(t_list **a);

//tri
void			swap_a(t_list **a);
void			swap_b(t_list **b);
int				push_a(t_list **a, t_list **b);
void			last_stack_element(t_list **a, t_list **b);
void			initialised_b(t_list **a, t_list **b);
void			push_b(t_list **a, t_list **b);
void			push_b_complete(t_list **a, t_list **b, t_list *tail_b);
void			rotate_a(t_list **a);
void			rotate_b(t_list **b);
void			ra_rb(t_list **a, t_list **b);
void			rotate_b(t_list **b);
void			rotate_ab(t_list **a, t_list **b);
void			reverse_rotate_a(t_list **a);
void			reverse_rotate_b(t_list **b);
void			reverse_rotate_ab(t_list **a, t_list **b);
void			last_stack_element(t_list **a, t_list **b);

//calculs
t_list			*find_max(t_list *list);
t_list			*find_min(t_list *list);
void			rotate_cost(t_list **a);
void			give_index(t_list **list);
int				above_median(t_list **pile, t_list *node);
t_list			*moove_cost(t_list **a, t_list **b, t_list *node_min);
void			rotate_cost_b(t_list **b);
void			rotate_cost_a(t_list **a, int i, int nbr, int len);
void			rotate_cost_a_2(t_list **a, int *i, int *nbr, int status);

#endif
