/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:38:47 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/07/31 15:38:51 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_s(va_list ap)
{
	int		count;
	char	*str;

	count = 0;
	str = va_arg(ap, char *);
	if (!str)
	{
		ft_putstr ("(null)");
		return (6);
	}
	while (*str)
	{
		write (1, str, 1);
		str ++;
		count++;
	}
	return (count);
}

int	print_c(va_list ap)
{
	char	c;

	c = (unsigned char)va_arg (ap, int);
	write (1, &c, 1);
	return (1);
}

int	print_percent(void)
{
	write (1, "%%", 1);
	return (1);
}
