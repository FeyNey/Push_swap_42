/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:55:59 by acoste            #+#    #+#             */
/*   Updated: 2024/07/30 02:06:05 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*before;

}	t_list;

void			ft_checkargs2(char **argv);
void			ft_checkargs(int n, char *argv);
void			check_doublon(t_list **head, int len, char **argv, int *b);
void			ft_errors(void);
void			check_doublon_error(t_list **head, char **argv, int *b);
char			**checkarg(int argc, char **argv, int *b);
t_list			*create_stack(char **argv, int *b);
int				check_value(long long int value, char **argv,
					int *b, t_list *stack);
long long int	ft_atoi(char *str);
t_list			*ft_lstnew(int content);
void			ft_lstadd_end(t_list **head, t_list *node);
int				stack_lenght(t_list *head);
void			free_stack(t_list *head);
void			free_or_no(char **argv, int c);
int				count_words(char *s, char c);
void			write_words(char *tab, char*s, char c);
void			freesplit(char **tab);
void			tab_split(char **tab, char *s, char c, int lastw);
char			**ft_split(char *s, char c);


#endif
