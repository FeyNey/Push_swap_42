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

char	**ft_split(char const *s, char c);
void	ft_checkargs(int n, char *argv);
void	ft_checkargs2(char** argv);
void	ft_errors(void);


#endif
