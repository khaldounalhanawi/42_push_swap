/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:03:33 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/07/28 18:24:31 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc (sizeof (t_list));
	if (!new)
		return (NULL);
	if (content)
		new->content = content;
	else
		new->content = NULL;
	new->index = NULL;
	new->cost = NULL;
	new->order = NULL;
	new->half = NULL;
	new->target = NULL;
	new -> next = NULL;
	return (new);
}
