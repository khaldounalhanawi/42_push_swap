#include "push_swap.h"

t_list *ft_lst_null_clear(t_list **list)
{
	if (!*list)
		return (NULL);
	ft_lstclear (list, free);
	return (NULL);
}