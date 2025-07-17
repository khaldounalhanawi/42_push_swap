#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"


int		isnum(char *str);
void	ft_exit(void *p1);
void	free_string_array(char **str);
char	**filter(int argc, char **argv);
void	*nullnfree(void *p1);
t_list	*initiate_chain (int *myarray,int argc);
void	swap(t_list **z, char *name);
void	rot(t_list **z, char *name);
void	rev_rot(t_list **z, char *name);
int		algorithm(t_list **a, int size);
void	push(t_list **a, t_list **b, char *name);
void chain_printer(t_list *my_list);
void double_rev_rot(t_list **a, t_list **b);
void double_rot(t_list **a, t_list **b);





#endif