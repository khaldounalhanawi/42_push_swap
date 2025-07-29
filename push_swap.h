/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:33:37 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/07/29 18:04:46 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

int		isnum(char *str);
void	ft_exit(void *p1);
void	free_string_array(char **str);
char	**filter(int argc, char **argv);
void	*nullnfree(void *p1);
t_list	*initiate_chain(int *myarray, int argc);
void	swap(t_list **z, char *name);
void	rot(t_list **z, char *name);
void	rev_rot(t_list **z, char *name);
void	push(t_list **a, t_list **b, char *name);
void	chain_printer(t_list *my_list);
void	double_rev_rot(t_list **a, t_list **b);
void	double_rot(t_list **a, t_list **b);
int		algo_five(t_list **mylist, int size);
void	algo_three(t_list **z);
void	algo_two(t_list **z);
t_list	*ft_lst_null_clear(t_list **list);
int		normalize(t_list *p);
t_list	*smallest(t_list *a);
void	finder(t_list *a, t_list *b);
void	tag(t_list *a);
void	find_target(t_list *a, t_list *b);
void	below_correct(t_list *a);
void	cal_cost(t_list *a);
t_list	*minimum_cost(t_list *a);
t_list	*find_zero(t_list *a);
void	final_organize(t_list **a);
void	reduce_a(t_list **a, t_list **b, int size);
int		single_action(t_list **a, t_list **b, t_list *record);
int		double_action(t_list **a, t_list **b, t_list *record);
int		hit(t_list **a, t_list **b, t_list *record);

#endif
