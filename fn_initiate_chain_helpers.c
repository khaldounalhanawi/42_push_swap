/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_initiate_chain_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:31:21 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/07/28 16:31:23 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_null_clear(t_list **list)
{
	if (!*list)
		return (NULL);
	ft_lstclear (list, free);
	return (NULL);
}
